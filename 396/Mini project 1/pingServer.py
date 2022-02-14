# UDP Ping Server
# Using random to simulate packet loss
import random
# Import socket module
from socket import *
probab = 0.1
# SOCK_STREAM for TCP, SOCK_DGRAM for UDP
serverSocket = socket(AF_INET, SOCK_DGRAM)
# Assign IP address and port number to socket
serverSocket.bind(('127.0.0.1', 6790))
print ("Server is ready to receive")
while True:
    # Receive client packet and arrival address
    message, address = serverSocket.recvfrom(2048)
    # Capitalize the message
    message = message.upper()
    # Error simulator goes here
    errored = random.random()
    if errored <= probab:
        message = "ERROR"
        serverSocket.sendto(message.encode(),address)
    # Your code ends here
    else:
        serverSocket.sendto(message, address)
        print(";)")

    if message == 'done!':
        print("Au revoir!")
        serverSocket.close()
