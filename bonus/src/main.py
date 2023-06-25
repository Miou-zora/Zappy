##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## main
##

import sys
import argparse
from .core import Core

def help():
    print("USAGE: \t./zappy_ai -p port -n name -h machine\n"
          "\tport\t is the port number\n"
          "\tname\t is the name of the team\n"
          "\tmachine\t is the name of the machine; localhost by default")

def main():
    if (sys.argv[1] == "-help" and len(sys.argv) == 2):
        help()
        return 0

    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument("-p", help="port number", dest="port", type=int, required=True)
    parser.add_argument("-n", help="name of the team", dest="name", type=str, required=True)
    parser.add_argument("-h", help="name of the machine", dest="machine", type=str, required=False, default="localhost")
    args = parser.parse_args()

    core = Core(args.machine, args.port, args.name)
    core.run()
