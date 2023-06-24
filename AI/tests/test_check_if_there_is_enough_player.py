##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_check_if_there_is_enough_player
##

import unittest
from src.AI import AI

class TestManagementClass(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.ai = AI("Team1")

    def test_check_if_there_is_enough_player_1(self):
        self.ai.user_ready_to_level_up = ["player1", "player2", "player3"]
        self.ai.level = 1
        self.assertEqual(self.ai.check_if_there_is_enough_player(), True)

    def test_check_if_there_is_enough_player_2(self):
        self.ai.user_ready_to_level_up = ["player1", "player2", "player3"]
        self.ai.level = 2
        self.assertEqual(self.ai.check_if_there_is_enough_player(), True)

    def test_check_if_there_is_enough_player_3(self):
        self.ai.user_ready_to_level_up = ["player1", "player2", "player3"]
        self.ai.level = 3
        self.assertEqual(self.ai.check_if_there_is_enough_player(), True)

    def test_check_if_there_is_enough_player_4(self):
        self.ai.user_ready_to_level_up = ["player1", "player2", "player3"]
        self.ai.level = 4
        self.assertEqual(self.ai.check_if_there_is_enough_player(), True)

    def test_check_if_there_is_enough_player_5(self):
        self.ai.user_ready_to_level_up = ["player1", "player2", "player3"]
        self.ai.level = 5
        self.assertEqual(self.ai.check_if_there_is_enough_player(), True)

    def test_check_if_there_is_enough_player_6(self):
        self.ai.user_ready_to_level_up = ["player1", "player2", "player3"]
        self.ai.level = 6
        self.assertEqual(self.ai.check_if_there_is_enough_player(), False)

    def test_check_if_there_is_enough_player_7(self):
        self.ai.user_ready_to_level_up = ["player1", "player2", "player3"]
        self.ai.level = 7
        self.assertEqual(self.ai.check_if_there_is_enough_player(), False)

    def test_check_if_there_is_enough_player_8(self):
        self.ai.user_ready_to_level_up = ["player1", "player2", "player3"]
        self.ai.level = 8
        self.assertEqual(self.ai.check_if_there_is_enough_player(), False)