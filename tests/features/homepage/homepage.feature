@api
Feature: Homepage content
  In order to communicate information about my pottery studio
  As a user
  I want to see the pottery on the site
  Background:
    Given a user with the following fields:
      | name | buffy |
      | pass | slayer |
      | roles | 2 |
    And a "pottery_item" node with the following fields:
      | title | pink cup |
      | author | buffy |
      | field_pottery_price | 10.00 |
      | field_inventory_count | 18 |
      | field_pottery_type | 1 |
    And a "pottery_item" node with the following fields:
      | title | red cup |
      | author | buffy |
      | field_pottery_price | 20.00 |
      | field_inventory_count | 9 |
      | field_pottery_type | 1 |
    And a "pottery_item" node with the following fields:
      | title | blue bowl |
      | author | buffy |
      | field_pottery_price | 40.00 |
      | field_inventory_count | 20 |
      | field_pottery_type | 3 |

  Scenario: Anonymous users can view the homepage
    Given I am an anonymous user
    When I go to "/home"
    Then the response status code should be 200

  Scenario: Users should see intro text on the homepage
    Given I am an anonymous user
    When I go to "/home"
    Then I should see the text "Welcome to the pottery site."

  Scenario: Users should see a login block
    Given I am an anonymous user
    When I go to "/home"
    Then I should see "User login"

  Scenario: User should see the titles of the newest pots
    Given I am an anonymous user
    When I go to "/home"
    Then I should see the text "blue bowl"

  Scenario: Users should see a total inventory block
    Given I am an anonymous user
    When I go to "/home"
    Then I should see "Total inventory: 847"

  Scenario: Anonymous users should see 'anonymous'
    Given I am an anonymous user
    When I go to "/home"
    Then I should see "anonymous"

  Scenario: Logged in users should see their user name
    Given I am logged in as "buffy"
    When I go to "/home"
    Then I should see "buffy"
