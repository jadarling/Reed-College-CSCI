# Import socket module
from socket import *
import pathlib
import time
host = '127.0.0.1'
port = 6010
defaultPath = pathlib.Path(__file__).parent
print(defaultPath)
# Prepare server socket
# SOCK_STREAM for TCP, SOCK_DGRAM for UDP
serverSocket = socket(AF_INET, SOCK_STREAM)
#bind serverSocket to host and port
serverSocket.bind((host,port))
#Listen for requests on serverSocket
serverSocket.listen()

while True:
    # Establish connection
    #Set timeout error length
    serverSocket.settimeout(360)
    print('Server listening...')
    #accept requests; create client socket 
    connectionSocket, addr = serverSocket.accept()
    try:
        #decode client message
        #Solution for OSError 10054; just make the server wait a second lol
        time.sleep(5)
        #recieve message from socket
        message = connectionSocket.recv(1024).decode()
        print(message)
        #parse the file reqeusted
        filename = message.split()[1]
        fileLocation = defaultPath / filename[1:]
        print(fileLocation)
        f = open(fileLocation, "rb")
        #designate the output data
        outputdata = f.read()
        # Send one HTTP header line to socket
        statusLine = 'HTTP/1.1 200 OK'
        connectionSocket.send(statusLine.encode())
        connectionSocket.send("\r\n".encode())
        connectionSocket.send("\r\n".encode())
        print("header sent")

        #Send object to client
        connectionSocket.send(outputdata)
        connectionSocket.send("\r\n".encode())
        print("body sent")
        #Close client socket
        connectionSocket.close()
    except IOError:
        # Send 404 message
        statusLine = 'HTTP/1.1 404 Not Found'
        connectionSocket.send(statusLine.encode())
        connectionSocket.send("\r\n".encode())
        connectionSocket.send("\r\n".encode())
        # Close client socket
        connectionSocket.close()
        break   
serverSocket.close()
