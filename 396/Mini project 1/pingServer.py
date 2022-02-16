# UDP Ping Server
# Using random to simulate packet loss
import random
# Import socket module
from socket import *
import time
probab = 0.9
# SOCK_STREAM for TCP, SOCK_DGRAM for UDP
serverSocket = socket(AF_INET, SOCK_DGRAM)
# Assign IP address and port number to socket
serverSocket.bind(('127.0.0.1', 6790))
print ("Server is ready to receive")
while True:
    try: 
        errored = random.random()
        if errored <= probab:
            print("packet dropped lol")
            time.sleep(5)
            continue
        # Receive client packet and arrival address
        message, address = serverSocket.recvfrom(2048)
        # Capitalize the message
        message = message.upper()
        # Error simulator goes here
        if message == 'done!':
            print("Au revoir!")
            serverSocket.close()
        else:
            serverSocket.sendto(message, address)
            print("succesfful")
            continue
    except TimeoutError:
        continue
    break
serverSocket.close()
