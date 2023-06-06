import sys
import argparse
from AI.client import Client

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
    parser.add_argument("-p", help="port number", type=int, required=True)
    parser.add_argument("-n", help="name of the team", type=str, required=True)
    parser.add_argument("-h", help="name of the machine", type=str, required=False, default="localhost")
    args = parser.parse_args()

    client = Client(args)
    client.connect()
    client.server_loop()
