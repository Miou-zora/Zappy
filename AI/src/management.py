##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## management
##

import os

if "AI" in os.getcwd():
  from src.client import Client
else:
  from AI.src.client import Client

class Management:
    """Management class
    Attributes:
        fonctions (dict): fonctions
        name (str): name
        output (str): output
    """
    def __init__(self, name: str):
        """__init__ function
        Args:
            name (str): name
        """
        self.fonctions: dict = {
            "message": self.message,
            "WELCOME": self.welcome,
            "other": self.other,
            "dead": self.death
        }
        self.name: str = name
        self.output: str = ""

    def welcome(self, message: str, client: Client):
        """welcome function
            this function is called when the server send a welcome message
        """
        self.output = self.name + "\n"

    def message(self, message: str, client: Client):
        """message function
            this function is called when the server send a message with broadcast
        Args:
            message (str): message
        """
        message = message.split(",")
        k: int = int(message[0].split()[1])
        message: str = message[1]

    def other(self, message: str, client: Client):
        """other function
            this function is called when the server send a message with no indication
        Args:
            message (str): message
        """
        words = message.split()
        if (len(words) == 1 and words[0].isnumeric()):  # client number
            clientNum = int(words[0])
        elif (len(words) == 2 and words[0].isnumeric() and words[1].isnumeric()): # map size
            x = int(words[0])
            y = int(words[1])

    def death(self, message: str, client: Client):
        """ death function
            this function is called when the server send a death message
        Args:
            message (str): message
        """
        print("End of connection")

    def execute_functions(self, message: str, client: Client):
        """execute_functions function
            this function execute the functions in the fonctions dict
        Args:
            message (str): message received from server
        """
        for key in self.fonctions.keys():
            if key == message[:len(key)]:
                self.fonctions[key](message, client)
                return
        self.fonctions["other"](message, client)