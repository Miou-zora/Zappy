##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Quick Fire Request
##

import socket
import sys
import os
from time import sleep

HEADER = '\033[95m'
OKBLUE = '\033[94m'
OKCYAN = '\033[96m'
OKGREEN = '\033[92m'
WARNING = '\033[93m'
FAIL = '\033[91m'
ENDC = '\033[0m'
BOLD = '\033[1m'
UNDERLINE = '\033[4m'

QUICK_FIRE_REQUEST = ["Hello\n", "World\n", "This\n", "Is\n", "A\n", "Quick\n", "Fire\n", "Request\n", "Test\n", "For\n", "Zappy\n"]
RES_DIC = {"Hello": 0, "World": 0, "This": 0, "Is": 0, "A": 0, "Quick": 0, "Fire": 0, "Request": 0, "Test": 0, "For": 0, "Zappy": 0}


class QuickFireRequest:

    def __init__(self, ip:str, port:int, numberClient:int) -> None:
        self.numberClient = numberClient
        self.port = port
        self.ip = ip
        self.clients = []
        print(OKGREEN + "Quick Fire request ready for " + str(numberClient) + " clients" + ENDC)

    def run(self, data:list) -> None:
        for i in range(self.numberClient):
            fork = os.fork()
            if fork == 0:
                client = Client(self.ip, self.port, i)
                client.send(data)
                sys.exit(0)
        sleep(4)

class AnalyseResult:

    def __init__(self, filepath:str, numberClient:int, data:str) -> None:
        self.filepath = filepath
        self.file = open(filepath, "r")
        self.lines = self.file.readlines()
        self.file.close()
        self.result = []
        self.numberClient = numberClient
        self.data = data

    def analyse(self) -> None:
        global RES_DIC
        numberConnection: int = 0

        for line in self.lines:
            for key, item in RES_DIC.items():
                if key in line:
                    RES_DIC[key] += 1
            if "New connection from" in line:
                numberConnection += 1
        self.display(numberConnection, RES_DIC)

    def display(self, numberConnection:int, results:dict) -> None:
        print(OKGREEN + "Quick Fire Request results" + ENDC)
        print(OKGREEN + "Number of connection: " + str(numberConnection) + "/" + str(self.numberClient) + ENDC)
        for key, item in results.items():
            if (item == self.numberClient):
                print(OKGREEN + key + ": " + str(item) + "/" + str(self.numberClient) + ENDC)
            else:
                print(FAIL + key + ": " + str(item) + "/" + str(self.numberClient) + ENDC)

class Client:
    def __init__(self, ip:str, port:int, id:int) -> None:
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.id = id
        self.connect(ip, port)

    def connect(self, ip:str, port:int) -> None:
        self.sock.connect((ip, port))

    def send(self, msg:list) -> None:
        for data in msg:
            self.sock.send(data.encode())
            sleep(0.1)

    def recv(self) -> str:
        return self.sock.recv(1024).decode()


def main():
    if len(sys.argv) != 5:
        print(FAIL + "Usage: ./client.py [ip] [port] [numberClient] [filepath]" + ENDC)
        sys.exit(84)
    quickFireRequest = QuickFireRequest(sys.argv[1], int(sys.argv[2]), int(sys.argv[3]))
    quickFireRequest.run(QUICK_FIRE_REQUEST)
    analyseResult = AnalyseResult(sys.argv[4], int(sys.argv[3]), "msz")
    analyseResult.analyse()
    return 0


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("KeyboardInterrupt")
        sys.exit(84)