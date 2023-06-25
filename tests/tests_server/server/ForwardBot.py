#!/usr/bin/env python3

import sys
import os
import socket
from time import sleep

MOVE = ["Forward", "Right", "Left", "Look", "Inventory", "Broadcast", "Connect_nbr", "Fork", "Eject", "Take", "Set", "Incantation"]

class Bot:

    def __init__(self, port, team):
        self.port = port
        self.team = team
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect(("localhost", self.port))
        sleep(1)
        print("Received: " + self.sock.recv(1024).decode())
        self.sock.send((team + '\n').encode())
        self.sock.send((self.team + "\n").encode())
        print("Received: " + self.sock.recv(1024).decode())

    def forward(self):
        self.sock.send(("Forward\n").encode())
        sleep(0.5)
        print("Received: " + self.sock.recv(1024).decode())
        self.sock.send("Take food\n".encode())
        sleep(0.5)
        print("Received: " + self.sock.recv(1024).decode())
        self.sock.send("Left\n".encode())
    def run(self):
        while True:
            self.forward()


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: ./ForwardBot.py port team")
        sys.exit(84)
    bot = Bot(int(sys.argv[1]), sys.argv[2])
    bot.run()