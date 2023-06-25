##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## client
##

import socket
import select

class Client:
    """Client class
    Attributes:
        server_sock (socket): socket
        adress (tuple): adress
        _close (bool): close
        fonctions (dict): fonctions
    """
    def __init__(self, machine: str, port: int):
        """__init__ function
        Args:
            args (argparse): args
        """
        self.server_sock: socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.adress: tuple = (machine, port)

    def connect(self):
        """connect function
            this function connect the socket to the server
        """
        self.server_sock.connect(self.adress)

    def close(self):
        """close function
            this function close the socket
        """
        self.server_sock.close()

    def select(self, inputs: list, outputs: list) -> tuple:
        """select function
            this function select the socket
        Args:
            inputs (list): inputs list
            outputs (list): outputs list
        Returns:
            tuple: readable, writable
        """
        readable, writable, _ = select.select(inputs, outputs, [], 0)
        return readable, writable

    def receive_data(self, sock: socket) -> str:
        """receive_data function
            this function receive data from the server
        Args:
            sock (socket): socket where to receive data
        Returns:
            str: data received
        """
        data = sock.recv(1024)
        if not data:
            return ""
        return data.decode()

    def send_data(self, sock: socket, data: str):
        """send_data function
            this function send data to the server
        Args:
            sock (socket): socket where to send data
            data (str): data to send
        """
        sock.send(data.encode())
