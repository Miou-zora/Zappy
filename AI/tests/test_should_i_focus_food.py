##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_should_i_focus_food
##

import unittest
from src.AI import AI

class TestManagementClass(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.ai = AI("Team1")

    def test_should_i_focus_food_no_inventory(self):
        self.ai.inventory = []
        self.ai.should_i_focus_food(True)
        self.assertEqual(self.ai.focus_food, False)

    def test_should_i_focus_food_with_inventory(self):
        self.ai.level = 1
        self.ai.inventory = ["food 1", "linemate 1"]
        self.ai.should_i_focus_food(True)
        self.assertEqual(self.ai.focus_food, True)

    def test_should_i_focus_food_with_inventory_and_much_food(self):
        self.ai.level = 1
        self.ai.inventory = ["food 9", "linemate 1"]
        self.ai.should_i_focus_food(False)
        self.assertEqual(self.ai.focus_food, True)

    def test_should_i_focus_food_with_inventory_and_not_much_food(self):
        self.ai.level = 4
        self.ai.inventory = ["food 40", "linemate 1"]
        self.ai.focus_food = True
        self.ai.should_i_focus_food(True)
        self.assertEqual(self.ai.focus_food, True)

    def test_should_i_focus_food_with_inventory_and_not_much_food_2(self):
        self.ai.level = 4
        self.ai.inventory = ["food 40", "linemate 1"]
        self.ai.focus_food = False
        self.ai.should_i_focus_food(True)
        self.assertEqual(self.ai.focus_food, False)