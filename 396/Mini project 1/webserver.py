# Import socket module
from socket import *
import pathlib
host = '127.0.0.1'
port = 6710
defaultPath = pathlib.Path(__file__).parent.resolve()
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
    serverSocket.settimeout(30)
    print('Server listening...')
    #accept requests; create client socket 
    connectionSocket, addr = serverSocket.accept()
    try:
        #decode client message
        message = connectionSocket.recv(1024).decode()
        print(message)
        #parse the file reqeusted
        filename = message.split()[1]
        fileLocation = str(defaultPath)+ "\\" + filename[1:]
        print(fileLocation)
        f = open(fileLocation, "rb")
        outputdata = f.read()
        # Send one HTTP header line to socket
        # Your code starts here
        statusLine = 'HTTP/1.1 200 OK'
        connectionSocket.send(statusLine.encode())
        connectionSocket.send("\r\n".encode())
        connectionSocket.send("\r\n".encode())
        print("header sent")
        # Your code ends here

        #Send object to client
        connectionSocket.send(outputdata)
        connectionSocket.send("\r\n".encode())
        print("body sent")
        connectionSocket.close()
    except IOError:
        # Send 404 message
        statusLine = 'HTTP/1.1 404 Not Found'
        connectionSocket.send(statusLine.encode())
        connectionSocket.send("\r\n".encode())
        connectionSocket.send("\r\n".encode())
        # Close client socket
        connectionSocket.close()
        # Your code ends here   
serverSocket.close()
