##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Heavy Load
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

class HeavyLoadClient:

    def __init__(self, ip:str, port:int, numberClient:int) -> None:
        self.numberClient = numberClient
        self.port = port
        self.ip = ip
        self.clients = []
        print(OKGREEN + "Heavy Load Tests ready for " + str(numberClient) + " clients" + ENDC)

    def run(self, data:str) -> None:
        for i in range(self.numberClient):
            fork = os.fork()
            if fork == 0:
                client = Client(self.ip, self.port, i)
                client.send(data)
                sys.exit(0)
        sleep(2)

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
        numberConnection: int = 0
        numberData: int = 0

        for line in self.lines:
            if "New connection from" in line:
                numberConnection += 1
            if self.data in line:
                numberData += 1
        self.display(numberConnection, numberData)

    def display(self, numberConnection:int, numberData:int) -> None:
        print(OKGREEN + "Heavy loads tests results" + ENDC)
        print(OKGREEN + "Number of connection: " + str(numberConnection) + "/" + str(self.numberClient) + ENDC)
        print(OKGREEN + "Number of data received: " + str(numberData) + "/" + str(self.numberClient) + ENDC)
        if numberConnection == self.numberClient:
            print(OKGREEN + "All clients has connected during the test" + ENDC)
        else:
            print(FAIL + "Some clients has not connected during the test" + ENDC)
        if numberData == self.numberClient:
            print(OKGREEN + "All clients has sent data during the test" + ENDC)
        else:
            print(FAIL + "Some clients loss their data during the test" + ENDC)

class Client:
    def __init__(self, ip:str, port:int, id:int) -> None:
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.id = id
        self.connect(ip, port)

    def connect(self, ip:str, port:int) -> None:
        self.sock.connect((ip, port))

    def send(self, msg:str) -> None:
        self.sock.sendall(msg.encode())

    def recv(self) -> str:
        return self.sock.recv(1024).decode()


def main():
    if len(sys.argv) != 5:
        print(FAIL + "Usage: ./client.py [ip] [port] [numberClient] [filepath]" + ENDC)
        sys.exit(84)
    heavyLoadClient = HeavyLoadClient(sys.argv[1], int(sys.argv[2]), int(sys.argv[3]))
    heavyLoadClient.run("msz\n")
    analyseResult = AnalyseResult(sys.argv[4], int(sys.argv[3]), "msz")
    analyseResult.analyse()
    return 0


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("KeyboardInterrupt")
        sys.exit(84)