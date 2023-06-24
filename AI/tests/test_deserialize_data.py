##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_deserialize_data
##

import unittest
from src.AI import AI

class TestManagementClass(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.ai = AI()

    def test_deserialize_data(self):
        self.ai.deserialize_data({"WELCOME": "test\n"})
        self.assertEqual(self.ai.output[0], "test\n")

    def test_deserialize_data_with_two_words_map_size(self):
        self.ai.deserialize_data({"map_size": (1, 2)})
        self.assertEqual(self.ai.map_size, (1, 2))

    def test_deserialize_data_with_two_words_client_num(self):
        self.ai.deserialize_data({"client_num": 1})
        self.assertEqual(self.ai.client_num, 1)

    def test_deserialize_data_with_two_words(self):
        self.ai.deserialize_data({"other": 1})
        self.assertEqual(self.ai.client_num, 0)
        self.assertEqual(self.ai.map_size, (0, 0))
        self.assertEqual(self.ai.output, [])

    def test_deserialize_data_with_two_words_and_one_other(self):
        data = {"other": 1, "WELCOME": "test\n"}
        self.ai.deserialize_data(data)
        self.assertEqual(self.ai.client_num, 0)
        self.assertEqual(self.ai.map_size, (0, 0))
        self.assertEqual(self.ai.output[0], "test\n")
        self.assertEqual(data, {"other": 1})

    def test_deserialize_data_with_message(self):
        self.ai.deserialize_data({"message": "test message"})
        self.assertEqual(self.ai.message, "test message")

    def test_deserialize_data_with_message_and_one_pos(self):
        self.ai.deserialize_data({"message": "test message", "k": 1})
        self.assertEqual(self.ai.message, "test message")

    def test_deserialize_data_with_client_nbr(self):
        self.ai.deserialize_data({"connect_nbr": 1})
        self.assertEqual(self.ai.connect_nbr, 1)

    def test_deserialize_data_with_inventory(self):
        self.ai.deserialize_data({"inventory": ["food 1", "linemate 2"]})
        self.assertEqual(self.ai.inventory, ['food 1', 'linemate 2'])

    def test_deserialize_data_with_look(self):
        self.ai.deserialize_data({"look": ["test", "message"]})
        self.assertEqual(self.ai.look, ["test", "message"])

    def test_deserialize_data_with_level(self):
        self.ai.deserialize_data({"level": 1})
        self.assertEqual(self.ai.level, 1)
