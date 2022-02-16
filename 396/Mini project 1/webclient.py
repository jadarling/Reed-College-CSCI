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
clientSocket = socket(AF_INET,SOCK_STREAM)
try:
    clientSocket.connect((host,port))
    print("connected")
    request= 'GET /'+obj+' HTTP/1.1'+"\r\n"
    clientSocket.send(request.encode())
    clientSocket.send("\r\n".encode())
    clientSocket.send("\r\n".encode())
    print("request sent")

    inputData = clientSocket.recv(2048)
    responseData= clientSocket.recv(2048)
    print("header: ")
    print(inputData)
    print()
    print("body: ")
    print(responseData)
    print("response recieved; goodbye")

    clientSocket.close()
except IOError:
    print("You're mom.")
    clientSocket.close()
