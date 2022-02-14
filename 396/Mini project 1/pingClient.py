# UDP Ping Client
from socket import *
import time
serverName = '127.0.0.1'
serverPort = 6790
clientSocket = socket(AF_INET, SOCK_DGRAM)
pingy='hewwo?'
doney="done!"
while True:
    for i in range(1,11):
        time.sleep(1)
        now = time.time()
        clientSocket.sendto(pingy.encode(), (serverName, serverPort))
        Message, serverAddress = clientSocket.recvfrom(2048)
        recievedAt = time.time()
        if Message.decode() == 'ERROR':
            print(str(i) + '*')
        else:
            totalTime = recievedAt-now
            rttMs = totalTime*1000
            line = str(i) +'. ' + str(Message) + ' RTT ' + str(rttMs) + 'ms'
            print(line)
    clientSocket.sendto(doney.encode(), (serverName, serverPort))
    print("done!")
    clientSocket.close()



