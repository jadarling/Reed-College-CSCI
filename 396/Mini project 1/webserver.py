# Import socket module
from socket import *

# Prepare server socket
# SOCK_STREAM for TCP, SOCK_DGRAM for UDP
serverSocket = socket(AF_INET, SOCK_STREAM)
# Your code starts here

#Your code ends here
while True:
    # Establish connection
    print('Server listening...')
    connectionSocket, addr = # Your code starts here # Your code ends here
    try:
        message = # Your code starts here # Your code ends here
        filename = message.split()[1]
        f = open(filename[1:])
        outputdata = # Your code starts here # Your code ends here

        # Send one HTTP header line to socket
        # Your code starts here

        # Your code ends here

        #Send object to client
        for i in range(0, len(outpudata)):
            connectionSocket.send(outputdata[i].encode())
        connectionSocket.send("\r\n".encode())

        connectionSocket.close()
    except IOError:
        # Send 404 message
        # Your code starts here

        # Your code ends here

        # Close client socket
        # Your code starts here

        # Your code ends here
    
serverSocket.close()
