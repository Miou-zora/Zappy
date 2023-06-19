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
        self.management.welcome("WELCOME")
        self.assertEqual(self.management.welcome("WELCOME"), {"WELCOME": "test\n"})
        self.assertEqual(self.management.need_response[0], "CLIENT_NUM")
        self.needs_response = []

    def test_other(self):
        self.management.need_response.append("CLIENT_NUM")
        self.assertEqual(self.management.other("1"), {"client_num": 1})
        self.assertEqual(self.management.need_response[0], "MAP_SIZE")
        self.needs_response = []

    def test_other_with_two_words(self):
        self.management.need_response.append("MAP_SIZE")
        self.assertEqual(self.management.other("1 2"), {"map_size": (1, 2)})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_forward(self):
        self.management.need_response.append("Forward")
        self.assertEqual(self.management.other("ok"), {})
        self.assertEqual(self.management.need_response, ["Forward"])
        self.needs_response = []

    def test_other_with_response_broadcast(self):
        self.management.need_response.append("BROADCAST")
        self.assertEqual(self.management.other("ok"), {})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_connect_nbr(self):
        self.management.need_response.append("CONNECT_NBR")
        self.assertEqual(self.management.other("1"), {"connect_nbr": 1})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_right(self):
        self.management.need_response.append("Right")
        self.assertEqual(self.management.other("ok"), {})
        self.assertEqual(self.management.need_response, ["Right"])
        self.needs_response = []

    def test_other_with_response_left(self):
        self.management.need_response.append("Left")
        self.assertEqual(self.management.other("ok"), {})
        self.assertEqual(self.management.need_response, ["Left"])
        self.needs_response = []

    def test_other_with_response_inventory(self):
        self.management.need_response.append("INVENTORY")
        self.assertEqual(self.management.other("[ tesf 1, sfghe 2, test 3, test 4, test 5, test 6, test 7 ]"), {"inventory": [' tesf 1', 'sfghe 2', 'test 3', 'test 4', 'test 5', 'test 6', 'test 7 ']})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_look(self):
        self.management.need_response.append("LOOK")
        self.assertEqual(self.management.other("[test, , allo]"), {"look": ["test", " ", " allo"]})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_take_ok(self):
        self.management.need_response.append("TAKE")
        self.assertEqual(self.management.other("ok"), {})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_test_ko(self):
        self.management.need_response.append("TAKE")
        self.assertEqual(self.management.other("ko"), {})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_set_ok(self):
        self.management.need_response.append("SET")
        self.assertEqual(self.management.other("ok"), {})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_set_ko(self):
        self.management.need_response.append("SET")
        self.assertEqual(self.management.other("ko"), {})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_incantation_ko(self):
        self.management.need_response.append("INCANTATION")
        self.assertEqual(self.management.other("ko"), {})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_incantation_ok(self):
        self.management.need_response.append("INCANTATION")
        self.assertEqual(self.management.other("Elevation underway"), {})
        self.assertEqual(self.management.need_response, ["LEVEL"])
        self.needs_response = []

    def test_other_with_response_level_ko(self):
        self.management.need_response.append("LEVEL")
        self.assertEqual(self.management.other("ko"), {})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_other_with_response_level_ok(self):
        self.management.need_response.append("LEVEL")
        self.assertEqual(self.management.other("Current level: 1"), {"level": 1})
        self.assertEqual(self.management.need_response, [])
        self.needs_response = []

    def test_message(self):
        self.assertEqual(self.management.message("message 1,2,3"), {})

    def test_message_with_no_comma(self):
        self.assertEqual(self.management.message("message 1"), {})

    def test_message_with_no_space(self):
        self.assertEqual(self.management.message("message1"), {})

    def test_message_with_no_space_and_comma(self):
        self.assertEqual(self.management.message("message1,2"), {})

    def test_message_negative(self):
        self.assertEqual(self.management.message("message -1,2"), {})

    @patch('sys.stdout', new_callable = StringIO)
    def test_death(self, stdout):
        self.assertEqual(self.management.death("dead"), {})
        self.assertEqual(stdout.getvalue(), "End of connection\n")

    def test_execute_functions(self):
        self.assertEqual(self.management.execute_functions("WELCOME"), {"WELCOME": "test\n"})
        self.assertEqual(self.management.execute_functions("1"), {"client_num": 1})
        self.assertEqual(self.management.execute_functions("1 2"), {"map_size": (1, 2)})
        self.assertEqual(self.management.execute_functions("dead"), {})
        self.assertEqual(self.management.execute_functions("ehjafjjeafhjea"), {})