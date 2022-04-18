# UDP Ping Server
# Using random to simulate packet loss
import random
# Import socket module
from socket import *
import time
probab = 0.30
# SOCK_STREAM for TCP, SOCK_DGRAM for UDP
serverSocket = socket(AF_INET, SOCK_DGRAM)
# Assign IP address and port number to socket
serverSocket.bind(('127.0.0.1', 6790))
print ("Server is ready to receive")
#Infinite loop
while True:
    try: 
        #Random number
        errored = random.random()
        #COmpare random number to probability of packet loss and if error...
        if errored <= probab:
            print("packet dropped lol")
            #Force timeOut on client machine
            time.sleep(5)
            #COntinue with loop
            continue
        # Receive client packet and arrival address
        message, address = serverSocket.recvfrom(2048)
        # Capitalize the message
        message = message.upper()
        #Ending message (doesn't work)
        if message == 'done!':
            print("Au revoir!")
            break
            #If no error, send message to client
        else:
            serverSocket.sendto(message, address)
            print("succesfful")
            continue
    #Timeout retry
    except TimeoutError:
        continue
    #Refuses to close beacause of broken message...
    break
serverSocket.close()
