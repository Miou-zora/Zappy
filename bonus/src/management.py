##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## management
##

import re
import asyncio

class Management:
    """Management class
    Attributes:
        fonctions (dict): fonctions
        team_name (str): team_name
    """
    def __init__(self, team_name: str):
        """__init__ function
        Args:
            team_name (str): team_name
        """
        self.fonctions: dict[str, function] = {
            "WELCOME": self.welcome,
            "other": self.other,
            "dead": self.death,
        }
        self.team_name: str = team_name
        self.responses: dict[str, str] = {
            "FORWARD": "ok",
            "EJECT": "ok|ko",
            "CLIENT_NUM": "[0-9]+|ko",
            "MAP_SIZE": "[0-9]+ [0-9]+",
        }
        self.need_response: list = []
        self.is_received: bool = False

    def welcome(self, message: str) -> dict:
        """welcome function
            this function is called when the server send a welcome message
        """
        self.need_response.append("CLIENT_NUM")
        self.is_received = True
        return {"WELCOME": f"{self.team_name}\n"}

    def get_rigtht_response(self, message: str) -> dict:
        """get_rigtht_response function
            this function is called when the server send a message
        Args:
            message (str): message
        """
        words = message.split()
        dict = {}
        if (self.need_response[0] == "CLIENT_NUM"):
            if (words[0] == "ko"):
                print("Error: bad team name")
                exit(84)
            dict["client_num"] = int(words[0])
            self.need_response.pop(0)
            self.need_response.append("MAP_SIZE")
            self.is_received = True
            return dict
        elif ("MAP_SIZE" == self.need_response[0]):
            dict["map_size"] = (int(words[0]), int(words[1]))
            self.need_response.pop(0)
        elif ("FORWARD" == self.need_response[0]):
            self.need_response.pop(0)
        elif ("EJECT" == self.need_response[0]):
            self.need_response.pop(0)
        self.is_received = True
        return dict

    def other(self, message: str) -> dict:
        """other function
            this function is called when the server send a message with no indication
        Args:
            message (str): message
        """
        if (self.need_response == []):
            return {}
        if (self.need_response[0] in self.responses.keys()):
            pattern = re.compile(self.responses[self.need_response[0]])
            if (re.match(pattern, message)):
                return self.get_rigtht_response(message)
        return {}

    def death(self, message: str) -> dict:
        """ death function
            this function is called when the server send a death message
        Args:
            message (str): message
        """
        print("End of connection")
        return {}

    async def execute_functions(self, message: str) -> dict:
        """execute_functions function
            this function execute the functions in the fonctions dict
        Args:
            message (str): message received from server
        """
        for key in self.fonctions.keys():
            if key == message.split()[0]:
                await asyncio.sleep(0)
                return (self.fonctions[key](message))
        await asyncio.sleep(0)
        return self.fonctions["other"](message)
