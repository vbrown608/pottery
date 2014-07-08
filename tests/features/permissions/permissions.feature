@api
Feature: User permissions
  In order to update information about inventory
  As a manager
  I want to set prices for pottery

  Scenario: Managers can edit the price field for pottery items
    Given I am logged in as a user with the "manager" role
    When I go to "/home"
    #Then

  Scenario: Potters cannot edit the price field for pottery items
    Given I am logged in as a user with the "potter" role
    When I go to "/home"
