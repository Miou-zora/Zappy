##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## AI
##

from typing import Any
from random import randint

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
        self.k: int = 0
        self.message: str = ""
        self.connect_nbr: int = 0
        self.inventory: list[str] = []
        self.look: list[str] = []
        self.count: int = 0
        self.level: int = 1
        self.values_map: list = [0, 2, 1, 3, 8, 6, 4, 5, 7, 14, 12, 10, 9, 11, 13, 15]
        self.player_pos: int = 0
        self.focus_food: bool = False

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
            "message": 'message',
            "connect_nbr": 'connect_nbr',
            "inventory": "inventory",
            "look": 'look',
            "level": 'level'
        }
        if (data_dict.get("WELCOME")):
            self.output.append(data_dict.get("WELCOME"))
            data_dict.pop("WELCOME")
        for key, value in list(data_dict.items()):
            if (deserialization_map.get(key)):
                self.__dict__[deserialization_map.get(key)] = value
                data_dict.pop(key)

    def get_item(self, item: str):
        """get_item function
            this function get an item
        Args:
            item (str): item to get
        """
        for i in range(len(self.inventory)):
            key, value = self.inventory[i].split()
            if key == item:
                return (int(value))

    def can_i_level_up(self) -> bool:
        """can_i_level_up function
            this function check if the ai can level up
        """
        if (self.level == 1 and self.get_item("linemate") == 1):
            return True
        if (self.level == 2 and self.get_item("linemate") == 1 and self.get_item("deraumere") == 1 and self.get_item("sibur") == 1):
            return True
        if (self.level == 3 and self.get_item("linemate") == 2 and self.get_item("sibur") == 1 and self.get_item("phiras") == 2):
            return True
        if (self.level == 4 and self.get_item("linemate") == 1 and self.get_item("deraumere") == 1 and self.get_item("sibur") == 2 and self.get_item("phiras") == 1):
            return True
        if (self.level == 5 and self.get_item("linemate") == 1 and self.get_item("deraumere") == 2 and self.get_item("sibur") == 1 and self.get_item("mendiane") == 3):
            return True
        if (self.level == 6 and self.get_item("linemate") == 1 and self.get_item("deraumere") == 2 and self.get_item("sibur") == 3 and self.get_item("phiras") == 1):
            return True
        if (self.level == 7 and self.get_item("linemate") == 2 and self.get_item("deraumere") == 2 and self.get_item("sibur") == 2 and self.get_item("mendiane") == 2 and self.get_item("phiras") == 2 and self.get_item("thystame") == 1):
            return True
        return False

    def should_i_focus_food(self):
        """should_i_focus_food function
            this function check if the ai should focus on food
        """
        if (len(self.inventory) == 0):
            return
        if (int(self.inventory[0].split()[1]) < 5):
            self.focus_food = True
        if (int(self.inventory[0].split()[1]) > 9):
            self.focus_food = False

    def take_object(self, object: str, idx: int):
        """take_object function
            this function take an object
        Args:
            object (str): object to take
        """
        self.output.append(f"Take {object}\n")
        self.need_response.append("TAKE")
        self.look[idx] = self.look[idx].replace(object, "", 1)
        self.look[idx] = self.look[idx].replace("  ", " ")
        self.update_inventory(object)

    def update_inventory(self, item: str):
        """ update_inventory function
            this function update the inventory
        Args:
            item (str): item to update
        """
        for i in range(len(self.inventory)):
            key, value = self.inventory[i].split()
            if key == item:
                value = str(int(value) + 1)
                self.inventory[i] = key + ' ' + value
                return

    def do_command(self, command: str):
        """do_command function
            this function do a command
        Args:
            command (str): command to do
        """
        self.output.append(command + "\n")
        self.need_response.append(command.upper())

    def add_actions_to_go_to_item(self, idx: int, item: str):
        """add_actions_to_go_to_item function
            this function add actions to go to an item
        Args:
            item (str): item to go to
        """
        if idx == self.player_pos:
            self.take_object(item, idx)
            return
        if idx >= 9 and idx <= 15 and self.player_pos == 6:
            self.do_command("Forward")
            self.player_pos = 12
            return
        elif idx >= 4 and idx <= 8 and self.player_pos == 2:
            self.do_command("Forward")
            self.player_pos = 6
            return
        elif idx >= 1 and idx <= 3 and self.player_pos == 0:
            self.do_command("Forward")
            self.player_pos = 2
            return
        if idx < self.player_pos:
            self.do_command("Left")
        elif idx > self.player_pos:
            self.do_command("Right")
        self.do_command("Look")
        self.player_pos = 0

    def no_item(self):
        """no_item function
            this function is called when there is no item
        """
        random_number = randint(0, 10)
        if (random_number == 8):
            self.do_command("Right")
        elif (random_number == 9):
            self.do_command("Left")
        self.do_command("Forward")
        self.player_pos = 0
        self.do_command("Look")

    def find_item(self, item: str, nbr: int = 1):
        """find_item function
            this function find an item
        Args:
            item (str): item to find
        """
        # TODO add a number of item to search
        if len(self.look) > 15:
            self.look = self.look[:15]
        for i in self.values_map:
            if (i > len(self.look)):
                break
            if item in self.look[i].split():
                self.add_actions_to_go_to_item(i, item)
                return
        self.no_item()

    def take_every_stones(self):
        """take_every_stones function
            this function take every stones
        """
        for i in self.values_map:
            if (i > len(self.look)):
                break
            if (len(self.look[i]) > 0):
                for j in range(len(self.look[i].split())):
                    looking_value = self.look[i].split()[j]
                    if (looking_value != "food" and looking_value != "player"):
                        self.add_actions_to_go_to_item(i, looking_value)
                        return
        self.no_item()

    def choose_action(self):
        """choose_action function
            this function choose the action to do
        """
        if (self.count == 0):
            self.do_command("Look")
            self.player_pos = 0
            self.count += 1
        if (self.count % 10 == 0):
            self.do_command("Inventory")
            self.count += 1
            return
        self.should_i_focus_food()
        if (self.focus_food):
            self.find_item("food")
        elif (self.can_i_level_up()):
            self.find_item("player", self.level)
        elif (self.look != []):
            self.take_every_stones()
        self.count += 1