##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## test_execute_functions
##

import unittest
from src.management import Management

class TestManagementClass(unittest.IsolatedAsyncioTestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.management = Management("test")

    async def test_execute_functions(self):
        self.assertEqual(await self.management.execute_functions("WELCOME"), {"WELCOME": "test\n"})
        self.assertEqual(await self.management.execute_functions("1"), {"client_num": 1})
        self.assertEqual(await self.management.execute_functions("1 2"), {"map_size": (1, 2)})
        self.assertEqual(await self.management.execute_functions("dead"), {})
        self.assertEqual(await self.management.execute_functions("ehjafjjeafhjea"), {})