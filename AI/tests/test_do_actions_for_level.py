##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_do_actions_for_level
##

import unittest
from src.AI import AI

class TestManagementClass(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.ai = AI()

    def test_do_actions_for_level_1(self):
        self.ai.level = 1
        self.ai.inventory = ["food 1", "linemate 1"]
        self.ai.look = [" player food linemate"]
        self.ai.do_action_for_level(self.ai.set_object)
        self.assertEqual(self.ai.look, [" linemate player food linemate"])
        self.assertEqual(self.ai.inventory, ["food 1", "linemate 0"])
        self.ai.do_action_for_level(self.ai.set_object)

    def test_do_actions_for_level_2(self):
        self.ai.level = 2
        self.ai.inventory = ["food 1", "linemate 1", "deraumere 1", "sibur 1"]
        self.ai.look = [" player food linemate deraumere sibur"]
        self.ai.do_action_for_level(self.ai.set_object)
        self.assertEqual(self.ai.look, [" sibur deraumere linemate player food linemate deraumere sibur"])
        self.assertEqual(self.ai.inventory, ["food 1", "linemate 0", "deraumere 0", "sibur 0"])
        self.ai.do_action_for_level(self.ai.set_object)

    def test_do_actions_for_level_3(self):
        self.ai.level = 3
        self.ai.inventory = ["food 1", "linemate 2", "sibur 1", "phiras 2", "thystame 1", "deraumere 1", "mendiane 1"]
        self.ai.look = [" player food linemate deraumere sibur"]
        self.ai.do_action_for_level(self.ai.set_object)
        self.assertEqual(self.ai.look, [" phiras phiras sibur linemate linemate player food linemate deraumere sibur"])
        self.assertEqual(self.ai.inventory, ["food 1", "linemate 0", "sibur 0", "phiras 0", "thystame 1", "deraumere 1", "mendiane 1"])
        self.ai.do_action_for_level(self.ai.set_object)
