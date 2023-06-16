##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## AI
##

from typing import Any

class AI:
    """AI class
    Attributes:
        data_dict (dict): data dict
    """
    def __init__(self):
        """__init__ function
        """
        self.output: str = ""
        self.need_response: str = ""
        self.map_size: tuple[int, int] = (0, 0)
        self.client_num: int = 0
        self.k: int = 0
        self.message: str = ""

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
            "k": 'k',
            "message": 'message'
        }
        for key, value in list(data_dict.items()):
            if (deserialization_map.get(key)):
                self.__dict__[deserialization_map.get(key)] = value
                data_dict.pop(key)

    def choose_action(self):
        """choose_action function
            this function choose the action to do
        """