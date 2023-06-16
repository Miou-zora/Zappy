##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## management
##

import re

class Management:
    """Management class
    Attributes:
        fonctions (dict): fonctions
        name (str): name
    """
    def __init__(self, name: str):
        """__init__ function
        Args:
            name (str): name
        """
        self.fonctions: dict[str, function] = {
            "message": self.message,
            "WELCOME": self.welcome,
            "other": self.other,
            "dead": self.death
        }
        self.name: str = name
        self.responses: dict[str, str] = {
            "Forward": "ok\n?",
            "Left": "ok\n?",
            "CLIENT_NUM": "[0-9]+\n?",
            "MAP_SIZE": "[0-9]+ [0-9]+\n?"
        }
        self.need_response: str = ""

    def welcome(self, message: str) -> dict:
        """welcome function
            this function is called when the server send a welcome message
        """
        self.need_response = "CLIENT_NUM"
        return {"WELCOME": f"{self.name}\n"}

    def message(self, message: str) -> dict:
        """message function
            this function is called when the server send a message with broadcast
        Args:
            message (str): message
        """
        message = message.split(",")
        if (len(message) < 2 or len(message[0]) > 2):
            return {}
        dict = {}
        dict["k"] = int(message[0].split()[1])
        dict["message"] = message[1]
        return dict

    def other(self, message: str) -> dict:
        """other function
            this function is called when the server send a message with no indication
        Args:
            message (str): message
        """
        words = message.split()
        dict = {}
        if (self.need_response == "CLIENT_NUM"):
            dict["client_num"] = int(words[0])
            self.need_response = "MAP_SIZE"
            return dict
        elif (self.need_response == "MAP_SIZE"):
            dict["map_size"] = (int(words[0]), int(words[1]))
            self.need_response = ""
            return dict
        if (self.need_response in self.responses.keys() and re.match(self.responses[self.need_response], message)):
            self.need_response = ""
        return dict

    def death(self, message: str) -> dict:
        """ death function
            this function is called when the server send a death message
        Args:
            message (str): message
        """
        print("End of connection")
        return {}

    def execute_functions(self, message: str) -> dict:
        """execute_functions function
            this function execute the functions in the fonctions dict
        Args:
            message (str): message received from server
        """
        for key in self.fonctions.keys():
            if key == message.split()[0]:
                return (self.fonctions[key](message))
        return self.fonctions["other"](message)
