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

    responseHeader, inputData = clientSocket.recv(2048)
    print(responseHeader)
    print(inputData)
    print("response recieved")
    html = open(inputData.decode(),'r')
    
    clientSocket.close()
except IOError:
    print("You're mom.")
    clientSocket.close()
