# UDP Ping Client
from socket import *
import time
serverName = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
pingy='HEAD / HTTP/1.1'+"\r\n"
for i in range(1,10):
    now = time.time()
    clientSocket.sendto(pingy.encode(), (serverName, serverPort))
    clientSocket.sendto("\r\n".encode(), (serverName, serverPort))
    clientSocket.sendto("\r\n".encode(),(serverName, serverPort))
    Message, serverAddress = clientSocket.recvfrom(2048)
    if Message.decode() == 'ERROR':
        print('*')
    else:
        recievedAt = time.time()
        totalTime = recievedAt-now
        line = str(i) +'. ' + str(Message) + ' RTT ' + str(totalTime) + 's'
        print(line)
clientSocket.close()



