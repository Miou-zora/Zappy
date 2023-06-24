##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_take_set_object
##

from src.AI import AI
import unittest

class TestStringMethods(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.ai = AI("Team1")

    def test_take_object(self):
        self.ai.inventory = ["food 1", "linemate 2"]
        self.ai.look = ["player food food"]
        self.ai.take_object("food", 0)
        self.assertEqual(self.ai.output[0], "Take food\n")
        self.assertEqual(self.ai.need_response[0], 'TAKE')
        self.assertEqual(self.ai.inventory, ["food 2", "linemate 2"])
        self.assertEqual(self.ai.look, ["player food"])


    def test_set_object(self):
        self.ai.inventory = ["food 1", "linemate 2"]
        self.ai.look = ["player food food"]
        self.ai.set_object("food", 1)
        self.assertEqual(self.ai.output[0], "Set food\n")
        self.assertEqual(self.ai.need_response[0], 'SET')
        self.assertEqual(self.ai.inventory, ["food 0", "linemate 2"])
        self.assertEqual(self.ai.look, ["player food food food"])