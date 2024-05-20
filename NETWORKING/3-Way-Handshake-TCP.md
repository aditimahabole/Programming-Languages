# 3 Way Handshake in TCP protocol
Three-Way Handshake
+ The three-way handshake is a method used in TCP/IP networks to establish a reliable connection between a client and server.

SYN (Synchronize):

+ The client sends a TCP packet with the SYN flag set to the server, indicating a request to establish a connection.
+ Ex: Client → Server: "SYN"

SYN-ACK (Synchronize-Acknowledge):

+ The server responds with a TCP packet with both SYN and ACK flags set,
+ acknowledging the client's request and indicating its readiness to establish a connection.
+ Example: Server → Client: "SYN-ACK"

ACK (Acknowledge):

+ The client responds with a TCP packet with the ACK flag set, confirming the connection establishment.
+ Example: Client → Server: "ACK"

![diagram-export-5-20-2024-1_16_52-PM](https://github.com/aditimahabole/Programming-Languages/assets/78752342/ba5c9dbe-d9f0-4b14-adc6-82f364ce6064)
