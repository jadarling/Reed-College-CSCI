# UDP Ping Client
from socket import *
import time
serverName = '127.0.0.1'
serverPort = 6790
clientSocket = socket(AF_INET, SOCK_DGRAM)
pingy='hewwo?'
doney='done!'
clientSocket.settimeout(5)
while True:
    for i in range(0,10):
        try: 
            now = time.time()
            clientSocket.sendto(pingy.encode(), (serverName, serverPort))
            Message, serverAddress = clientSocket.recvfrom(2048)
            recievedAt = time.time()
            totalTime = recievedAt-now
            rttMs = totalTime*1000
            line = str(i) +'. ' + str(Message) + ' RTT ' + str(rttMs) + 'ms'            
            print(line)
        except TimeoutError:
            print(str(i) +'. ' + '*')
            continue
        # if u DONT recieve a packet: print(str(i) + '*')
    break
clientSocket.sendto(doney.encode(), (serverName, serverPort))
print("done!")
clientSocket.close()



