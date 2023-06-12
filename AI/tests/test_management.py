##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_management
##

import unittest
from io import StringIO
from unittest.mock import patch
from src.management import Management

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

    @patch('sys.stdout', new_callable = StringIO)
    def test_death(self, stdout):
        self.management.death("dead", None)
        self.assertEqual(stdout.getvalue(), "End of connection\n")

