##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## core
##

from typing import Any

from .client import Client
from .AI import AI
from .management import Management
import asyncio
import threading

class Core:
    """ Core class
    Attributes:
        client (Client): client
        _is_running (bool): is running
        inputs (list): inputs
        outputs (list): outputs
        received_data (str): received data
        management (Management): management class
        ai (AI): ai class
    """
    def __init__(self, machine: str, port: int, name: str):
        """__init__ function
        Args:
            machine (str): machine
            port (int): port
            name (str): name
        """
        self.client: Client = Client(machine, port)
        self.ai: AI = AI(name)
        self.management: Management = Management(name)
        self._is_running: bool = True
        self.inputs: list = [self.client.server_sock]
        self.outputs: list = [self.client.server_sock]
        self.received_data: str = ""
        self.data_dict: dict[str, Any] = {}

    def run(self, is_dad: bool = True):
        """run function
            this function run the client
        """
        self.client.connect()
        self.loop(is_dad)

    def stop(self):
        """stop function
            this function close the client and stop the main loop
        """
        self._is_running = False
        self.client.close()

    def response_management(self):
        """response_management function
            this function manage the response
        """
        if self.ai.need_response != []:
            self.management.need_response.extend(self.ai.need_response)
            if len(self.management.need_response) != len(self.ai.output):
                self.ai.output = []
                self.ai.need_response = []
            self.ai.need_response = []

    async def use_data(self, message):
        tmp_dict = await self.management.execute_functions(message)
        if "message" in tmp_dict:
            if "message" not in self.data_dict:
                self.data_dict.update(tmp_dict)
                if not isinstance(self.data_dict["message"], list):
                    self.data_dict["message"] = [self.data_dict["message"]]
            else:
                if not isinstance(self.data_dict["message"], list):
                    self.data_dict["message"] = [self.data_dict["message"]]
                self.data_dict["message"].append(tmp_dict["message"])
        else:
            self.data_dict.update(tmp_dict)

    async def parse_received_data(self):
        """parse_received_data function
            this function parse the data received from the server
        Args:
            data (str): data received from server
        """
        data = self.received_data
        while "\n" in data:
            message, data = data.split("\n", 1)
            await self.use_data(message)
        return data

    def receive_data_from_server(self, readable: list) -> bool:
        """receive_data function
            this function receive data from the server
        Args:
            sock (socket): socket where to receive data
        Returns:
            str: data received
        """
        for sock in readable:
            if sock == self.client.server_sock:
                receive = self.client.receive_data(sock)
                if not receive:
                    print("Server disconnected")
                    self.stop()
                    return False
                self.received_data += receive
                self.received_data = asyncio.run(self.parse_received_data())
        return True

    def send_data_to_server(self, writable: list):
        """send_data function
            this function send data to the server
        Args:
            sock (socket): socket where to send data
            data (str): data to send
        """
        for sock in writable:
            if sock is self.client.server_sock:
                if self.ai.output and self.management.is_received == True:
                    self.client.send_data(sock, self.ai.output[0])
                    self.management.is_received = False
                    self.ai.output.pop(0)

    def select_in_thread(self):
        readable, writable = self.client.select(self.inputs, self.outputs)
        self.receive_data_from_server(readable)
        self.send_data_to_server(writable)

    def loop(self, is_dad: bool):
        """loop function
            this function is the main loop of the AI
        """
        while self._is_running:
            select_thread = threading.Thread(target=self.select_in_thread)
            select_thread.start()

            if self.data_dict:
                self.ai.deserialize_data(self.data_dict)
                self.data_dict = {}

            if self.ai.map_size != (0, 0) and not self.management.need_response and self.management.is_received:
                self.ai.choose_action(is_dad)

            self.response_management()

            select_thread.join()
