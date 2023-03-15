import socket
HEADER = 64 
PORT = 5051
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "Disconnect!"
SERVER = socket.gethostbyname(socket.gethostname()) 
print("Host Name : ",socket.gethostname())
ADDR = (SERVER, PORT)

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect(ADDR)

def send(msg):
    message = msg.encode(FORMAT)
    msg_len = len(message)
    send_len = str(msg_len).encode(FORMAT)
    send_len += b' ' * (HEADER - len(send_len))
    # we are adding remaining as spaces so to make it 64
    client.send(send_len)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))
send("Hello Guys")
send("Disconnect!")

