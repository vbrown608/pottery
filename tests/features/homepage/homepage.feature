@api
Feature: Homepage content
  In order to communicate information about my pottery studio
  As a user
  I want to see the pottery on the site

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
    # Then I should see...

  Scenario: User should see the titles of the newest pots
    Given a user with the following fields:
      | name | buffy |
      | pass | slayer |
      | roles | 2 |
    And a "pottery_item" node with the following fields:
      | title | pink cup |
      | author | buffy |
      | field_price | 10.00 |
      | field_inventory_count | 10 |
    When I go to "/home"
    Then I should see the text "pink cup"
