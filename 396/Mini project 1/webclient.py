from socket import *
from urllib import response

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

    responseHeader = clientSocket.recv(4096), clientSocket.recv(4096), clientSocket.recv(4096)
    inputData = clientSocket.recv(4096)
    print(responseHeader)
    print("response recieved")
    html = open(inputData,'r')
    

    clientSocket.close()
except IOError:
    print("Your mom.")
    clientSocket.close()
