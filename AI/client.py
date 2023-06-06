import socket
import sys

class Client:
    def __init__(self, args):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.adress = (args.h, args.p)
        self.name = args.n
        self._close = False
        self.fonctions = {
            "WELCOME": self.welcome
        }

    def connect(self):
        self.sock.connect(self.adress)
        self.sock.setblocking(False)

    def close(self):
        if self._close:
            self.sock.close()

    def welcome(self):
        name = self.name + "\n"
        self.sock.send(name.encode())
        self.sock.setblocking(True)
        data = self.sock.recv(1024).decode()
        clientNum, x, y = data.split()
        self.sock.setblocking(False)

    def server_loop(self):
        received_data = ""
        while True:
            try:
                data = self.sock.recv(1024)
                if not data:
                    break

                received_data += data.decode()
                while "\n" in received_data:
                    message, received_data = received_data.split("\n", 1)
                    if message in self.fonctions:
                        self.fonctions[message]()
                    else:
                        print(f"Unknown message: {message}", file=sys.stderr)
            except socket.error as e:
                error_code = e.errno
                if error_code == socket.errno.EWOULDBLOCK:
                    continue
                else:
                    print(f"Socket error: {str(e)}", file=sys.stderr)
                    break
