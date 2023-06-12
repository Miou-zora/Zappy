##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_management
##

import unittest
from src.management import Management

# write tests to test the management class

class TestManagementClass(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.management = Management("test")

    def test_welcome(self):
        self.management.welcome("WELCOME", None)
        self.assertEqual(self.management.output, "test\n")

    def test_other(self):
        self.management.other("1", None)
        self.assertEqual(self.management.output, "")

    def test_other_with_two_words(self):
        self.management.other("1 2", None)
        self.assertEqual(self.management.output, "")

    def test_message(self):
        self.management.message("message 1,2,3", None)
        self.assertEqual(self.management.output, "")

