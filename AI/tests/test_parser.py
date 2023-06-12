##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## tests_parser
##

from src.core import Core
import unittest

class TestStringMethods(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.core = Core("localhost", 4242, "test")

    def test_parse_received_data_with_newline(self):
        self.core.received_data = "WELCOME\n"
        self.assertEqual(self.core.parse_received_data(), "")
        self.core.client.close()

    def test_parse_received_data_without_newline(self):
        self.core.received_data = "message 1"
        self.assertEqual(self.core.parse_received_data(), "message 1")
        self.core.client.close()

    def test_parse_received_data_with_two_newline(self):
        self.core.received_data = "message 1,2,3\nmessage 4,5,6\n"
        self.assertEqual(self.core.parse_received_data(), "")
        self.core.client.close()

    def test_parse_received_data_with_two_newline_and_data(self):
        self.core.received_data = "message 1,2,3\nmessage 4,5,6\nmess"
        self.assertEqual(self.core.parse_received_data(), "mess")
        self.core.client.close()

if __name__ == '__main__':
    unittest.main()
