##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## core
##

import os

if "AI" in os.getcwd():
  from src.client import Client
  from src.management import Management
else:
  from AI.src.client import Client
  from AI.src.management import Management

class Core:
    """ Core class
    Attributes:
        client (Client): client
        management (Management): management
        _is_running (bool): is running
        inputs (list): inputs
        outputs (list): outputs
        received_data (str): received data
    """
    def __init__(self, machine: str, port: int, name: str):
        """__init__ function
        Args:
            machine (str): machine
            port (int): port
            name (str): name
        """
        self.client: Client = Client(machine, port)
        self.management: Management = Management(name)
        self._is_running: bool = True
        self.inputs: list = [self.client.server_sock]
        self.outputs: list = []
        self.received_data: str = ""

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
            self.management.execute_functions(message, self.client)
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
                self.client.send_data(sock, self.management.output)
                self.outputs.remove(sock)
                self.management.output = ""
            else:
                pass

    def loop(self):
        while self._is_running:
            readable, writable = self.client.select(self.inputs, self.outputs)
            if (self.receive_data_from_server(readable) == False):
                return
            self.send_data_to_server(writable)
