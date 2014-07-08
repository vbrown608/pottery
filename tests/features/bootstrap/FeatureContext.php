<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Event\EntityEvent;

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

}
