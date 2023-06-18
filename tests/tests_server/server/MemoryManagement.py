##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## MemoryManagement
##

import sys

HEADER = '\033[95m'
HEADER = '\033[95m'
OKBLUE = '\033[94m'
OKCYAN = '\033[96m'
OKGREEN = '\033[92m'
WARNING = '\033[93m'
FAIL = '\033[91m'
ENDC = '\033[0m'
BOLD = '\033[1m'
UNDERLINE = '\033[4m'

class ValgrindParser:

    def __init__(self, filepath:str) -> None:
        self.filepath = filepath
        self.file = open(filepath, "r")
        self.lines = self.file.readlines()
        self.file.close()
        self.result = {
            "definitely lost": 0,
            "indirectly lost": 0,
            "possibly lost": 0,
            "still reachable": 0,
            "suppressed": 0,
            "Invalid read": 0,
            "Invalid write": 0,
            "uninitialised value(s)": 0,
            "invalid free()": 0,
        }

    def parse(self) -> None:
        for line in self.lines:
            for key in self.result.keys():
                if key in line:
                    self.result[key] += 1
        

    def print(self) -> None:
        failed = False
        printed = False
        print("Errors found: ")
        for key, item in self.result.items():
            if (item > 0):
                print("\t" + WARNING  + key + ": " + str(item) + ENDC)
                failed = True
                printed = True
        if not printed:
            print("\t" + OKGREEN + "No errors found" + ENDC)
        if failed:
            print(FAIL + "Memory management report for " + self.filepath + " failed" + ENDC)
            for line in self.lines:
                print(line, end="")
        else:
            print(OKGREEN + "Memory management report for " + self.filepath + " passed" + ENDC)
                


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(FAIL + "Usage: python3 MemoryManagement.py [filepath]" + ENDC)
        sys.exit(84)
    parser = ValgrindParser(sys.argv[1])
    parser.parse()
    parser.print()