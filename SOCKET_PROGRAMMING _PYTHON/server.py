import socket
import threading
# put all message handling stuff in sep threads 
# for each client that connects to our server
# -----------------------------------------------------
PORT = 5051 
# SERVER = "192.168.56.1" 
SERVER = socket.gethostbyname(socket.gethostname()) 
# this code gets the above ip address automatically
# we do not have to search for ip address
print("Server IP Address : " , SERVER)
ADDR = (SERVER,PORT)
print("Socket : " , ADDR)
HEADER = 64
# 64 bytes
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "Disconnect!"
# -----------------------------------------------------
# AF_INET = Address Format, Internet = IP Addresses
# SOCK_STREAM socket type is implemented on the 
# Transmission Control Protocol/Internet Protocol (TCP/IP) protocol.
# A stream socket provides for the bidirectional, 
# reliable, sequenced, and un-duplicated flow of data without record boundaries.
server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind(ADDR) #making socket ip + port
# -----------------------------------------------------
def handle_client(conn,addr):
    # handle individual connection between client and server
    # it will run parallel for each client 
    print(f"[NEW CONNECTION] {addr} connected. ")
    is_connected  = True
    while is_connected:
        # wait te receive info from client and do something with that and print it to screen
        msg_len = conn.recv(HEADER).decode(FORMAT)
        # takes bytes as an argument so we use HEADER
        # then decode using FORMAT utf-8
        # converting byte to string
        if msg_len:
            msg_len = int(msg_len)
            print(msg_len)
            msg = conn.recv(msg_len).decode(FORMAT)
            if msg == DISCONNECT_MESSAGE:
                print(f"You got {msg}.")
                is_connected = False
            print(f"[{addr}] --> {msg}")
            conn.send("Message received".encode(FORMAT))
    
    conn.close()
    # print("Connection Closed")
# --------------------------------------------------------------
def start():
    # handle all communication between server and client
    server.listen() #listening for new connections
    print(f"[LISTENING] on server: {SERVER}")
    while True: #infinite loop until server crashes or we shut down
        conn, addr = server.accept() 
        #this will wait for new connection to the server
        # and we are storing what ip and port it came from
        thread = threading.Thread(target = handle_client,args = (conn, addr))
        thread.start()
        # print active connections
        print(f"[ACTIVE CONNECTIONS] {threading.active_count() - 1} ")
        # threading.activeCount():tell how many threads are active 
        # no of threads = no of client connected
        # as 1 thread is always running at first so we are doing - 1

print("[STARTING] server is starting...")
start()


