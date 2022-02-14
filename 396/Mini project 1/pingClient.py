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
        if Message.decode() == 'ERROR':
            print(str(i) + '*')
        else:
            recievedAt = time.time()
            totalTime = recievedAt-now
            line = str(i) +'. ' + str(Message) + ' RTT ' + str(totalTime) + 's'
            print(line)
    clientSocket.sendto(doney.encode(), (serverName, serverPort))
    print("done!")
    clientSocket.close()



