<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Event\EntityEvent;
use Behat\Behat\Event\StepEvent;

//
// Require 3rd-party libraries here:
//
//   require_once 'PHPUnit/Autoload.php';
//   require_once 'PHPUnit/Framework/Assert/Functions.php';
//

/**
 * Features context.
 */
// class FeatureContext extends BehatContext
class FeatureContext extends Drupal\DrupalExtension\Context\DrupalContext
{
  /**
   * Initializes context.
   * Every scenario gets its own context object.
   *
   * @param array $parameters context parameters (set them up through behat.yml)
   */
  public function __construct(array $parameters)
  {
      // Initialize your context here
  }

  /**
 * @Given /^a user with the following fields:$/
 */
  public function aUserWithTheFollowingFields(TableNode $fields) {
    $row_hash = $fields->getRowsHash();
    if (isset($row_hash['name'])) {
      $user = user_load_by_name($row_hash['name']);
      $new = FALSE;

      if (empty($user)) {
        $user = (object) array();
        $new = TRUE;
      }

      foreach ($row_hash as $field => $value) {
        switch ($field) {
          case 'roles':
            $user->roles = array($value);
            break;
          default:
            $user->{$field} = $value;
        }
      }

      // Set a password.
      if (!isset($user->pass)) {
        $user->pass = Random::name();
      }

      if ($new) {
        $this->dispatcher->dispatch('beforeUserCreate', new EntityEvent($this, $user));
        $this->getDriver()->userCreate($user);
        $this->dispatcher->dispatch('afterUserCreate', new EntityEvent($this, $user));
      }
      else {
        user_save($user);
      }

      $this->addUser($user);
    }
  }

  /**
   * @Given /^(?:a|an) "([^"]*)" node with the following fields:$/
   */
  public function anNodeWithTheFollowingFields($type, TableNode $fields) {
    $node = new stdClass();
    $node->type = $type;
    $node->language = 'und';
    foreach ($fields->getRowsHash() as $field => $value) {
      switch ($field) {
        case 'author':
          $user = user_load_by_name($value);
          if (!empty($user)) {
            $node->uid = $user->uid;
          }
          break;

        default:
          $node->{$field} = $value;
      }
    }

    $this->dispatcher->dispatch('beforeNodeCreate', new EntityEvent($this, $node));
    $saved = $this->getDriver()->createNode($node);
    $this->dispatcher->dispatch('afterNodeCreate', new EntityEvent($this, $saved));
    $this->nodes[] = $saved;
    // Set internal browser on the node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));
  }

  /** @AfterStep */
  public function takeScreenshotOnFail(StepEvent $event) {
    if ($event->hasException()) {
      $driver = $this->getSession()->getDriver();
      $class = get_class($driver);
      $filepath = $this->getDrupalParameter('debug_files_path');

      if ($class == 'Behat\Mink\Driver\GoutteDriver') {

        // @TODO: Get wkhtmltoimage to work.
        // @see https://groups.google.com/forum/#!topic/behat/dbkzdOLzF6s
        // @see http://extensions.behat.org/symfony2/

        // $html = $this->getSession()->getPage()->getContent();
        // // Generating an Image using KnP's Snappy
        // $image = new \Knp\Snappy\Image();
        // $image->generateFromHtml($html, $filepath . '/' . sprintf('goutte_%s_%s.%s', date('c'), uniqid('', true), 'png'));

        $html = $this->getSession()->getDriver()->getContent();
        $filename = sprintf('%s_%s_%s.%s', $this->getMinkParameter('browser_name'), date('c'), uniqid('', true), 'html');
        $filepath = $filepath ? $filepath : (ini_get('upload_tmp_dir') ? ini_get('upload_tmp_dir') : sys_get_temp_dir());
        file_put_contents($filepath . '/' . $filename, $html);
      }
      elseif ($class == 'Behat\Mink\Driver\Selenium2Driver') {
        $this->saveScreenshot(NULL, $filepath);
      }
    }
  }

  /**
   * Helper function to find nodes by type and title.
   *
   * @return node
   */
  public function nodeLoadByTitle($type, $title) {
    $query = db_select('node', 'n');
    $query->condition('n.title', $title);
    $query->condition('n.type', $type);
    $query->condition('n.status', 1);
    $query->fields('n', array('nid'));
    $query_result = $query->execute();
    $nid = NULL;

    foreach ($query_result as $record) {
      $nid = $record->nid;
    }

    $node_not_found = TRUE;

    if (!is_null($nid)) {
      $node = node_load($nid);
      if ($node) {
        $node_not_found = FALSE;
        return $node;
      }
    }

    if ($node_not_found) {
      throw new \Exception(sprintf('There is no %s node with the title %s.', $type, $title));
    }
  }

  /**
   * @When /^I go to the "([^"]*)" form for the "([^"]*)" node with the title "([^"]*)"$/
   */
  public function iGoToTheFormForTheNodeWithTheTitle($form_type, $type, $title) {
    $node = $this->nodeLoadByTitle($type, $title);
    $path = 'node/' . $node->nid . '/' . strtolower($form_type);
    $this->getSession()->visit($this->locatePath($path));
  }

  /**
   * @When /^I go to the "([^"]*)" node with the title "([^"]*)"$/
   */
  public function iGoToTheNodeWithTheTitle($type, $title) {
    $node = $this->nodeLoadByTitle($type, $title);
    $this->getSession()->visit($this->locatePath('/node/' . $node->nid));
  }

}
