@api
Feature: User permissions
  In order to update information about inventory
  As a manager
  I want to set prices for pottery

  Scenario: Managers can edit the price field for pottery items
    Given a user with the following fields:
      | name | giles |
      | pass | librarian |
      | roles | 3 |
    And I am logged in as "giles"
    And a "pottery_item" node with the following fields:
      | title | goblet of darkness |
      | author | giles |
      | field_pottery_price | 10.00 |
      | field_inventory_count | 10 |
    # And I go to the "pottery_item" node with the title "goblet of darkness"
    # When I follow "Edit"
    When I go to the "edit" form for the "pottery_item" node with the title "goblet of darkness"
    Then I should see the text "Price"

  Scenario: Potters cannot edit the price field for pottery items
    Given a user with the following fields:
      | name | spike |
      | pass | vampire |
      | roles | 5 |
    And a user with the following fields:
      | name | giles |
      | pass | librarian |
      | roles | 4 |
    And I am logged in as "spike"
    And a "pottery_item" node with the following fields:
      | title | pink cup |
      | author | giles |
      | field_pottery_price | 10.00 |
      | field_inventory_count | 10 |
    When I go to the "edit" form for the "pottery_item" node with the title "pink cup"
    Then I should not see the text "Price"
