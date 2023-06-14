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
        self.ai: AI = AI()
        self.management: Management = Management(name)
        self._is_running: bool = True
        self.inputs: list = [self.client.server_sock]
        self.outputs: list = []
        self.received_data: str = ""
        self.data_dict: dict[str, Any] = {}

    def run(self):
        """run function
            this function run the client
        """
        self.client.connect()
        self.loop()

    def stop(self):
        """stop function
            this function close the client and stop the main loop
        """
        self._is_running = False
        self.client.close()

    def parse_received_data(self):
        """parse_received_data function
            this function parse the data received from the server
        Args:
            data (str): data received from server
        """
        data = self.received_data
        while "\n" in data:
            message, data = data.split("\n", 1)
            self.data_dict.update(self.management.execute_functions(message))
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
            if sock is self.client.server_sock:
                receive = self.client.receive_data(sock)
                if not receive:
                    print("Server disconnected")
                    self.stop()
                    return False
                self.received_data += receive
                self.received_data = self.parse_received_data()
                self.outputs.append(sock)
            else:
                pass
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
                if not self.ai.output:
                    self.client.send_data(sock, self.ai.output)
                    self.outputs.remove(sock)
                    self.ai.output = ""

    def loop(self):
        """loop function
            this function is the main loop of the AI
        """
        while self._is_running:
            readable, writable = self.client.select(self.inputs, self.outputs)
            if (self.receive_data_from_server(readable) == False):
                return
            if self.data_dict:
                self.ai.deserialize_data(self.data_dict)
            self.ai.choose_action()
            self.send_data_to_server(writable)
