##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## AI
##

from typing import Any
from random import randint
from uuid import uuid4
from .utils import clamp, encrypt_string
import sys
import os

class AI:
    """AI class
    Attributes:
        data_dict (dict): data dict
    """
    def __init__(self, team_name: str):
        """__init__ function
        """
        self.output: list = []
        self.need_response: list = []
        self.map_size: tuple[int, int] = (0, 0)
        self.client_num: int = 0
        self.message: list = []
        self.connect_nbr: int = 0
        self.inventory: list[str] = []
        self.look: list[str] = []
        self.count: int = 0
        self.level: int = 1
        self.values_map: list = [0, 2, 1, 3, 8, 6, 4, 5, 7, 14, 12, 10, 9, 11, 13, 15]
        self.player_pos: int = 0
        self.focus_food: bool = False
        self.incantation: bool = False
        self.name: str = str(uuid4())
        self.user_to_join: tuple[str, int] = ("", 0)
        self.user_ready_to_level_up: list[str] = []
        self.previous_level: int = 1
        self.is_ko: bool = False
        self.team_name: str = team_name
        self.team_size: int = 0
        self.do_nothing: bool = False
        self.max_team_level: int = 1
        self.dead_players: list[str] = []

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
            "message": 'message',
            "connect_nbr": 'connect_nbr',
            "inventory": "inventory",
            "look": 'look',
            "level": 'level',
            "incantation": 'incantation',
        }
        if (data_dict.get("WELCOME")):
            self.output.append(data_dict.get("WELCOME"))
            data_dict.pop("WELCOME")
        for key, value in list(data_dict.items()):
            if (deserialization_map.get(key)):
                self.__dict__[deserialization_map.get(key)] = value
                if not value:
                    self.is_ko = True
                data_dict.pop(key)

    def broadcast_message(self, message: str):
        """broadcast_message function
            this function is called when the server send a message with broadcast
        Args:
            message (str): message
        """
        encrypted_message =  encrypt_string(message, self.team_name)
        self.output.append(f"Broadcast {encrypted_message}\n")
        self.need_response.append("BROADCAST")

    def get_item(self, item: str) -> int:
        """get_item function
            this function get an item
        Args:
            item (str): item to get
        """
        for i in range(len(self.inventory)):
            key, value = self.inventory[i].split()
            if key == item:
                return (int(value))
        return 0

    def can_i_level_up(self, is_dad: bool) -> bool:
        """can_i_level_up function
            this function check if the ai can level up
        """
        if (is_dad):
            return False
        if (self.level == 1 and self.get_item("linemate") >= 1):
            return True
        if (self.level == 2 and self.get_item("linemate") >= 1 and self.get_item("deraumere") >= 1 and self.get_item("sibur") >= 1):
            return True
        if (self.level == 3 and self.get_item("linemate") >= 2 and self.get_item("sibur") >= 1 and self.get_item("phiras") >= 2):
            return True
        if (self.level == 4 and self.get_item("linemate") >= 1 and self.get_item("deraumere") >= 1 and self.get_item("sibur") >= 2 and self.get_item("phiras") >= 1):
            return True
        if (self.level == 5 and self.get_item("linemate") >= 1 and self.get_item("deraumere") >= 2 and self.get_item("sibur") >= 1 and self.get_item("mendiane") >= 3):
            return True
        if (self.level == 6 and self.get_item("linemate") >= 1 and self.get_item("deraumere") >= 2 and self.get_item("sibur") >= 3 and self.get_item("phiras") >= 1):
            return True
        if (self.level == 7 and self.get_item("linemate") >= 2 and self.get_item("deraumere") >= 2 and self.get_item("sibur") >= 2 and self.get_item("mendiane") >= 2 and self.get_item("phiras") >= 2 and self.get_item("thystame") >= 1):
            return True
        return False

    def should_i_focus_food(self, is_dad: bool):
        """should_i_focus_food function
            this function check if the ai should focus on food
        """
        if (len(self.inventory) == 0):
            return
        if (is_dad):
            if (int(self.inventory[0].split()[1]) < 30):
                self.focus_food = True
            if (int(self.inventory[0].split()[1]) > 40):
                self.focus_food = False
        else:
            if (int(self.inventory[0].split()[1]) < 5):
                self.broadcast_message(f"{self.name} {self.team_name} dead")
                if (self.connect_nbr < 17):
                    self.do_command("Fork")
            if (int(self.inventory[0].split()[1]) < 5 + 5 * self.level):
                self.focus_food = True
                self.broadcast_message(f"{self.name} foods")
            if (int(self.inventory[0].split()[1]) > 5 + 10 * self.level):
                self.focus_food = False

    def remove_from_look(self, item: str, idx: int = 0):
        """remove_from_look function
            this function remove an item from look
        Args:
            item (str): item to remove
        """
        self.look[idx] = self.look[idx].replace(item, "", 1)
        self.look[idx] = self.look[idx].replace("  ", " ")

    def take_object(self, object: str, idx: int):
        """take_object function
            this function take an object
        Args:
            object (str): object to take
        """
        self.output.append(f"Take {object}\n")
        self.need_response.append("TAKE")
        self.remove_from_look(object, idx)
        self.update_inventory(object)

    def set_object(self, object: str, nbr: int):
        """set_object function
            this function set an object
        Args:
            object (str): object to set
        """
        for nbr in range(nbr, 0, -1):
            self.output.append(f"Set {object}\n")
            self.need_response.append("SET")
            self.look[0] = self.look[0].replace(" ", f" {object} ", 1)
            self.update_inventory(object, False)

    def update_inventory(self, item: str, add: bool = True):
        """ update_inventory function
            this function update the inventory
        Args:
            item (str): item to update
        """
        for i in range(len(self.inventory)):
            key, value = self.inventory[i].split()
            if key == item:
                value = str(int(value) + (1 if add else -1))
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
        if  1 <= idx <= 3:
            self.do_command("Forward")
            self.player_pos = 2
        elif 4 <= idx <= 8:
            self.do_command("Forward")
            self.do_command("Forward")
            self.player_pos = 6
        elif 9 <= idx <= 15:
            self.do_command("Forward")
            self.do_command("Forward")
            self.do_command("Forward")
            self.player_pos = 12
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

    def find_item(self, item: str):
        """find_item function
            this function find an item
        Args:
            item (str): item to find
        """
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

    def check_if_there_is_enough_player(self) -> bool:
        """check_if_there_is_enough_player function
            this function check if there is enough player
        """
        number_of_player = len(self.user_ready_to_level_up) + 1
        if (self.level == 8):
            return False
        return (number_of_player >= clamp((self.level - self.level % 2), 1, 8))

    def do_action_for_level(self, action):
        if (self.level == 1):
            action("linemate", 1)
        elif (self.level == 2):
            action("linemate", 1)
            action("deraumere", 1)
            action("sibur", 1)
        elif (self.level == 3):
            action("linemate", 2)
            action("sibur", 1)
            action("phiras", 2)
        elif (self.level == 4):
            action("linemate", 1)
            action("deraumere", 1)
            action("sibur", 2)
            action("phiras", 1)
        elif (self.level == 5):
            action("linemate", 1)
            action("deraumere", 2)
            action("sibur", 1)
            action("mendiane", 3)
        elif (self.level == 6):
            action("linemate", 1)
            action("deraumere", 2)
            action("sibur", 3)
            action("phiras", 1)
        elif (self.level == 7):
            action("linemate", 2)
            action("deraumere", 2)
            action("sibur", 2)
            action("mendiane", 2)
            action("phiras", 2)
            action("thystame", 1)

    def check_someone_is_ready_to_level_up(self, is_dad: bool) -> bool:
        """ check_someone_is_ready_to_level_up function
            this function check if someone is ready to level up
        """
        if not self.user_to_join or is_dad:
            return False
        if self.user_to_join[0]:
            return True
        return False

    def join_someone_ready_to_level_up(self):
        """ join_someone_ready_to_level_up function
            this function join someone ready to level up
        """
        if (self.user_to_join[1] == 1):
            self.do_command("Forward")
            self.do_command("Look")
        if (self.user_to_join[1] == 5):
            self.do_command("Left")
            self.do_command("Left")
            self.do_command("Forward")
        if (self.user_to_join[1] in [6, 7, 8]):
            self.do_command("Right")
            self.do_command("Forward")
        if (self.user_to_join[1] in [2, 3, 4]):
            self.do_command("Left")
            self.do_command("Forward")
        if (self.user_to_join[1] == 0):
            self.broadcast_message(f"{self.name} ready with {self.user_to_join[0]}")
            return
        self.broadcast_message(f"{self.name} comming to {self.user_to_join[0]}")

    def parse_received_messages(self, is_dad: bool):
        """parse_received_messages function
            this function parse the received messages from broadcast
        """
        if (self.message == []):
            return
        for words in self.message:
            split_words = words.split()
            if (len(split_words) >= 4 and split_words[1] not in self.dead_players and split_words[2] == self.team_name and split_words[3] == "dead" and is_dad):
                self.dead_players.append(split_words[1])
                self.team_size -= 1
            if (len(split_words) >= 5 and split_words[2] == "ready" and split_words[3] == "level" and is_dad):
                self.max_team_level = max(self.max_team_level, int(split_words[4]))
            if (len(split_words) >= 5 and split_words[2] == "ready" and split_words[3] == "level" and int(split_words[4]) == self.level and not is_dad):
                self.user_to_join = (split_words[1], int(split_words[0][0]))
            if (len(split_words) >= 5 and split_words[2] == "ready" and split_words[3] == "with" and split_words[4] == self.name and split_words[0][0] == "0" and not is_dad):
                if (split_words[1] not in self.user_ready_to_level_up):
                    self.user_ready_to_level_up.append(split_words[1])
            if (len(split_words) >= 4 and split_words[2] == "incantation" and split_words[3] == "starts" and split_words[1] == self.user_to_join[0] and not is_dad):
                self.user_to_join = ("", 0)
            if (len(split_words) >= 3 and split_words[2] == "foods" and split_words[1] == self.user_to_join[0] and not is_dad):
                self.user_to_join = ("", 0)
            if (len(split_words) >= 3 and split_words[2] == "foods" and split_words[1] in self.user_ready_to_level_up and not is_dad):
                self.user_ready_to_level_up.remove(split_words[1])
        self.message = []

    def ko_received(self) -> bool:
        """ko_received function
            this function is called when the ai is ko
        """
        if (self.is_ko):
            self.output = []
            self.need_response = []
            self.count = 0
            self.is_ko = False
            return True
        return False

    def block_vision(self):
        """block_vision function
            this function block the vision for 15 cases (3 lines)
        """
        if self.look and len(self.look) >= 17:
            self.look = self.look[:16]

    def level_up_actions(self):
        """level_up_actions function
            this function is called when the ai level up
        """
        if (self.level != self.previous_level):
            self.previous_level = self.level
            self.count = 0
            self.user_to_join = ("", 0)

    def do_incantation(self):
        """do_incantation function
            this function do the incantation
        """
        self.broadcast_message(f"{self.name} incantation starts")
        self.do_action_for_level(self.set_object)
        self.do_command("Incantation")

    def create_first_family(self, is_dad: bool):
        """create_first_family function
            this function create the first family
        """
        if (self.client_num > 6):
            self.client_num = 6
        if (self.client_num > 0):
            if (is_dad):
                pid = os.fork()
                if pid == 0:
                    from AI.main import main
                    main(False)
                    sys.exit(0)
                else:
                    self.client_num -= 1
                    self.team_size += 1

    def should_i_fork(self, is_dad: bool):
        """should_i_fork function
            this function check if the ai should fork
        """
        if (self.connect_nbr > 0 and self.team_size < self.max_team_level * 2 and is_dad):
            return True
        return False

    def fork_actions(self):
        """fork_actions function
            this function do the fork actions
        """
        self.do_command("Fork")
        pid = os.fork()
        if pid == 0:
            from AI.main import main
            main(False)
            sys.exit(0)
        else:
            self.connect_nbr -= 1
            self.team_size += 1

    def choose_action(self, is_dad: bool):
        """choose_action function
            this function choose the action to do
        """
        if (self.do_nothing):
            self.broadcast_message(f"{self.name} {self.team_name} dead")
            return
        # print("name:", self.name, "level", self.level)
        if (is_dad):
            print("team size:", self.team_size, "max team level:", self.max_team_level)
        self.level_up_actions()
        self.create_first_family(is_dad)
        if (self.count == 0):
            self.do_command("Connect_nbr")
            self.do_command("Look")
        if (self.ko_received()):
            return
        if (self.count % 5 == 0):
            self.do_command("Inventory")
            self.do_command("Connect_nbr")
            if (is_dad and self.connect_nbr < 17):
                self.do_command("Fork")
        self.block_vision()
        self.should_i_focus_food(is_dad)
        self.parse_received_messages(is_dad)
        if (self.focus_food):
            self.find_item("food")
        elif (self.should_i_fork(is_dad)):
            self.fork_actions()
        elif (self.check_someone_is_ready_to_level_up(is_dad)):
            self.user_ready_to_level_up = []
            self.join_someone_ready_to_level_up()
        elif self.can_i_level_up(is_dad) and self.check_if_there_is_enough_player():
            self.do_incantation()
        elif (self.can_i_level_up(is_dad)):
            self.broadcast_message(f"{self.name} ready level {str(self.level)}")
        elif (self.look != [] and not is_dad):
            self.take_every_stones()
        self.count += 1