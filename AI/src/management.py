##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## management
##

import re
import asyncio
from .utils import decrypt_string

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
            "message": self.message,
            "WELCOME": self.welcome,
            "other": self.other,
            "dead": self.death,
            "Elevation": self.elevation,
            "Current": self.current_level,
        }
        self.team_name: str = team_name
        self.responses: dict[str, str] = {
            "FORWARD": "ok",
            "RIGHT": "ok",
            "LEFT": "ok",
            "CLIENT_NUM": "[0-9]+|ko",
            "MAP_SIZE": "[0-9]+ [0-9]+",
            "CONNECT_NBR": "[0-9]+",
            "BROADCAST": "ok",
            "INVENTORY": "\[ ?(([a-zA-Z]+ [0-9]+(, )){6}[a-zA-Z]+ [0-9]+) ?\]",
            "LOOK": "\[ ?(([a-zA-Z]*)( ?,?)*)* ?\]",
            "TAKE": "ok|ko",
            "SET": "ok|ko",
            "INCANTATION": "Elevation underway|ko",
            "LEVEL": "Current level: [0-9]+|ko",
            "FORK": "ok",
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

    def message(self, message: str) -> dict:
        """message function
            this function is called when the server send a message with broadcast
        Args:
            message (str): message
        """
        check = message.split(",")
        if (len(check) < 2 or len(check[0].split()) < 2 or int(check[0].split()[1]) < 0):
            return {}
        dict = {}
        dict["message"] = f"{int(check[0].split()[1])}, {decrypt_string(check[1][1:], self.team_name)}"
        return dict

    def elevation(self, message: str) -> dict:
        """elevation function
            this function is called when the server send a message with incantation
        Args:
            message (str): message
        """
        dict = {}
        if (self.need_response != [] and self.need_response[0] == "INCANTATION"):
            self.need_response.pop(0)
            self.is_received = True
            self.need_response.append("LEVEL")
        dict["incantation"] = True
        return dict

    def current_level(self, message: str) -> dict:
        """current function
            this function is called when the server send a message with current level
        Args:
            message (str): message
        """
        dict = {}
        dict["level"] = int(message.split()[2])
        dict["incantation"] = False
        if (self.need_response != [] and self.need_response[0] == "LEVEL"):
            self.need_response.pop(0)
            self.is_received = True
        return dict

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
        elif ("CONNECT_NBR" == self.need_response[0]):
            dict["connect_nbr"] = int(words[0])
            self.need_response.pop(0)
        elif ("LOOK" == self.need_response[0]):
            dict["look"] = message[1:-1].split(",")
            self.need_response.pop(0)
        elif ("INVENTORY" == self.need_response[0]):
            dict["inventory"] = message[1:-1].split(", ")
            self.need_response.pop(0)
        elif ("TAKE" == self.need_response[0]):
            if (words[0] == "ok"):
                dict["take"] = True
            else:
                dict["take"] = False
            self.need_response.pop(0)
        elif ("SET" == self.need_response[0]):
            if (words[0] == "ok"):
                dict["set"] = True
            else:
                dict["set"] = False
            self.need_response.pop(0)
        elif (self.need_response[0] in ["FORWARD", "RIGHT", "LEFT", "BROADCAST", "FORK"]):
            self.need_response.pop(0)
        elif ("INCANTATION" == self.need_response[0]):
            if (words[0] == "ko"):
                dict["incantation"] = False
            self.need_response.pop(0)
        elif ("LEVEL" == self.need_response[0]):
            if (words[0] == "ko"):
                dict["incantation"] = False
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
