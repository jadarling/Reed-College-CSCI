from socket import *
from urllib import response

from nbformat import read

"""
host = str(input("Host: "))
port = int(input("Port: "))
obj = input("Object: ")
"""
host = ''
port = 6010
obj= 'jim.html'
#Create TCP socket
clientSocket = socket(AF_INET,SOCK_STREAM)
try:
    #Connect to server socket
    clientSocket.connect((host,port))
    print("connected")
    #Send HTTP request
    request= 'GET /'+obj+' HTTP/1.1'+"\r\n"
    clientSocket.send(request.encode())
    clientSocket.send("\r\n".encode())
    clientSocket.send("\r\n".encode())
    print("request sent")
#Recieve header (inputData) and body of requested object (responseData) and print them
    inputData = clientSocket.recv(2048)
    responseData= clientSocket.recv(2048)
    print("header: ")
    print(inputData)
    print()
    print("body: ")
    print(responseData)
    print("response recieved; goodbye")

    clientSocket.close()
    #Error exception
except IOError:
    print("You're mom.")
    clientSocket.close()
