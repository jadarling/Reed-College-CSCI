# UDP Ping Client
from socket import *
import time
serverName = '127.0.0.1'
serverPort = 6790
clientSocket = socket(AF_INET, SOCK_DGRAM)
pingy='hewwo?'
doney='done!'
#Set Timeout for error simulator
clientSocket.settimeout(5)
while True:
    #10 pings...
    for i in range(0,10):
        try: 
            #log the time
            now = time.time()
            #send message
            clientSocket.sendto(pingy.encode(), (serverName, serverPort))
            #recieve message
            Message, serverAddress = clientSocket.recvfrom(2048)
            #log the time 
            recievedAt = time.time()
            #Total time in seconds (recieved-sent)
            totalTime = recievedAt-now
            #Convert to Ms
            rttMs = totalTime*1000
            #Construct line to print to console
            line = str(i) +'. ' + str(Message) + ' RTT ' + str(rttMs) + 'ms' 
            #Print it!           
            print(line)
            #If there is a "timeout" error...
        except TimeoutError:
            #Print star + line
            print(str(i) +'. ' + '*')
            #Continue with loop
            continue
    #After for loop, break While loop
    break
#Send goodbye message (does not work)
clientSocket.sendto(doney.encode(), (serverName, serverPort))
print("done!")
#Close socket
clientSocket.close()



