##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## client
##

import sys
import socket
import time
import os
import subprocess

import socket
import sys
from time import sleep

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

class Client:

    def __init__(self, ip, port):
        self.ip = ip
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
        self.response = ""
        self.connect()
        self.receive()

    def send(self, msg) -> None:
        self.sock.send(msg.encode())

    def receive(self) -> str:
        self.response = ""
        self.response = self.sock.recv(4096).decode()
        return self.response

    def close(self) -> None:
        self.sock.close()
        self.data_sock.close()

    def connect(self) -> None:
        self.sock.connect((self.ip, self.port))
        print("Connected to " + self.ip + ":" + str(self.port))
        self.receive()
        if not "WELCOME" in self.response:
            print(bcolors.FAIL + "Error: connection failed" + bcolors.ENDC)
            print("Server response: " + self.response)
            sys.exit(84)

    def reset(self):
        self.close()
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connect()

    def send_receive(self, msg, expected):
        print(bcolors.OKCYAN + "Sending: " + msg + bcolors.ENDC + " expecting: " + expected)
        self.send(msg)
        sleep(0.1)
        self.receive()
        if expected not in self.response:
            print(bcolors.FAIL + "Error: expected " + expected + " got " + self.response + bcolors.ENDC)
            sys.exit(84)



if __name__ == "__main__":
    try:
        if len(sys.argv) != 3:
            print("Usage: python3 client.py ip port")
            sys.exit(84)
        client = Client(sys.argv[1], int(sys.argv[2]))
        client.send_receive("Tests", "OK")
        client.send_receive("msz", "OK")
        print(bcolors.OKGREEN + "Tests done" + bcolors.ENDC)
    except ConnectionResetError as e:
        print(bcolors.FAIL + "Server suddenly closed the connection" + bcolors.ENDC)
        print (e)
        client.Analyze()
        sys.exit(84)
    except Exception as e:
        print(bcolors.FAIL + "Error: something went wrong")
        print(e)
        print(bcolors.ENDC)
        sys.exit(84)

