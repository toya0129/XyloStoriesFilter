import socket

class SocketClient():
    client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    def __init__(self, host, port):
        self.client.connect((host, port))
        print("Socket Connected")

    def __del__(self):
        self.client.close()
        print("Server Disconected")

    def SendData(self, data):
        try:
            send_data = str(data) + "\n"
            self.client.send(send_data.encode('utf-8'))
        except BrokenPipeError:
            pass

    # サーバーとの接続確認
    def CheckServer(self):
        try:
            check = self.client.getpeername()
        except OSError:
            raise ConnectionRefusedError
