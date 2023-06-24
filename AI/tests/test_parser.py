##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## tests_parser
##

from src.core import Core
import unittest
import asyncio

class TestStringMethods(unittest.IsolatedAsyncioTestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.core = Core("localhost", 4242, "test")

    async def test_parse_received_data_with_newline(self):
        self.core.received_data = "WELCOME\n"
        self.assertEqual(await self.core.parse_received_data(), "")
        self.core.data_dict = {}
        self.core.client.close()

    async def test_parse_received_data_without_newline(self):
        self.core.received_data = "message 1"
        self.assertEqual(await self.core.parse_received_data(), "message 1")
        self.core.data_dict = {}
        self.core.client.close()

    async def test_parse_received_data_with_two_newline(self):
        self.core.received_data = "message 1,2,3\nmessage 4,5,6\n"
        self.assertEqual(await self.core.parse_received_data(), "")
        self.core.data_dict = {}
        self.core.client.close()

    async def test_parse_received_data_with_two_newline_and_data(self):
        self.core.received_data = "message 1,2,3\nmessage 4,5,6\nmess"
        self.assertEqual(await self.core.parse_received_data(), "mess")
        self.core.data_dict = {}
        self.core.client.close()

    async def test_parse_received_data_with_two_newline_and_data_and_newline(self):
        self.core.received_data = "message 1, hello boys\nmessage 1, arbre\n"
        self.assertEqual(await self.core.parse_received_data(), "")
        self.assertEqual(self.core.data_dict, {"message": ["1, hello boys", "1, arbre"]})
        self.core.data_dict = {}
        self.core.client.close()

    async def test_parse_received_data_two_messages(self):
        self.core.management.need_response.append("INCANTATION")
        self.core.received_data = "message 1, hello boys\nmessage 1, arbre\nElevation underway\n"
        self.assertEqual(await self.core.parse_received_data(), "")
        self.assertEqual(self.core.data_dict, {"message": ["1, hello boys", "1, arbre"], "incantation": True})
        self.core.data_dict = {}
        self.core.client.close()

    async def test_parse_received_data_one_messages_and_data(self):
        self.core.received_data = "message 1, hello boys\nElevation underway\n"
        self.assertEqual(await self.core.parse_received_data(), "")
        self.assertEqual(self.core.data_dict, {"message": ["1, hello boys"], "incantation": True})
        self.core.data_dict = {}
        self.core.client.close()

if __name__ == '__main__':
    unittest.main()
