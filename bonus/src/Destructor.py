##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## AI
##

from typing import Any
from random import randint
from uuid import uuid4
import sys
import os

class AI:
    """AI class
    Attributes:
        data_dict (dict): data dict
    """
    def __init__(self):
        """__init__ function
        """
        self.output: list = []
        self.need_response: list = []
        self.map_size: tuple[int, int] = (0, 0)
        self.client_num: int = 0

    def deserialize_data(self, data_dict: dict[str, Any]):
        """save_data function
            this function save the data received from the server
        Args:
            data (str): data received
        """
        deserialization_map = {
            "WELCOME": 'output',
            "map_size": 'map_size',
            "client_num": 'client_num',
        }
        if (data_dict.get("WELCOME")):
            self.output.append(data_dict.get("WELCOME"))
            data_dict.pop("WELCOME")
        for key, value in list(data_dict.items()):
            if (deserialization_map.get(key)):
                self.__dict__[deserialization_map.get(key)] = value
                data_dict.pop(key)

    def do_command(self, command: str):
        """ do_command function
            this function do the command
        """
        self.output.append(f"{command}\n")
        self.need_response.append(command.upper())

    def choose_action(self):
        """choose_action function
            this function choose the action to do
        """
        self.do_command("Forward")
        self.do_command("Eject")