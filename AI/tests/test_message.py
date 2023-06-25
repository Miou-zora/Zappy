##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_message
##

import unittest
from src.management import Management
from src.utils import encrypt_string

class TestMessage(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.management = Management("test")

    def test_good_message(self):
        string = "hello la famille"
        self.assertEqual(self.management.message(f"message 1, {encrypt_string(string, self.management.team_name)}"), {"message": "1, hello la famille"})

    def test_message(self):
        string = "2"
        self.assertEqual(self.management.message(f"message 1, {encrypt_string(string, self.management.team_name)}"), {"message": "1, 2"})

    def test_message_with_no_comma(self):
        self.assertEqual(self.management.message("message 1"), {})

    def test_message_with_no_space(self):
        self.assertEqual(self.management.message("message1"), {})

    def test_message_with_no_space_and_comma(self):
        self.assertEqual(self.management.message("message1,2"), {})

    def test_message_negative(self):
        self.assertEqual(self.management.message("message -1,2"), {})