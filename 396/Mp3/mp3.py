
from email import header
import socket
import io
import time
from tkinter.messagebox import RETRY
import typing
import struct
from urllib import response
import miniproject3
import miniproject3.logging
DEF_TIME_OUT = .2
ACK = b'1'
NAK = b'0'
FIN = b'010'
FINACK = b'111'
"""
ACK 1 = 101
ACK 0 = 001
NAK 1 = 100
NAK 0 = 000
FIN =   010
"""


def send(sock: socket.socket, data: bytes):
    """
    Implementation of the sending logic for sending data over a slow,
    lossy, constrained network.

    Args:
        sock -- A socket object, constructed and initialized to communicate
                over a simulated lossy network.
        data -- A bytes object, containing the data to send over the network.
    """

    # Naive implementation where we chunk the data to be sent into
    # packets as large as the network will allow, and then send them
    # over the network, pausing half a second between sends to let the
    # network "rest" :)
    logger = miniproject3.logging.get_logger("mp3-sender")
    chunk_size = miniproject3.MAX_PACKET-3
    pause = .1
    offsets = range(0, len(data), chunk_size)
    seq = b'0'
    sock.settimeout(DEF_TIME_OUT)
    data_list = [data[i:i + chunk_size] for i in offsets]
    try: 
        for chunk in data_list:
            try:
                packet = seq + b'0' + ACK + chunk 
                tmp = packet
                sock.send(packet)
                responser = sock.recv(3)
                print("Rx HEAD")
                print(responser) 
                if sock.recv == b'000'or '100':
                    print()
                    print("NAK")
                    sock.send(tmp)
                if sock.recv == b'101' or '001':
                    if seq == b'1':
                        seq = b'0'
                    if seq == b'0':
                        seq = b'1'
                    print("ACK")
                    continue
            except TimeoutError:
                sock.send(tmp)
                continue

        try: 
            print("END")
            sock.send(FIN)
            if sock.recv == FIN:
                sock.send(FINACK)
                sock.close

        except TimeoutError:
            sock.close()

    except TimeoutError:
        return

def recv(sock: socket.socket, dest: io.BufferedIOBase) -> int:
    """
    Implementation of the receiving logic for receiving data over a slow,
    lossy, constrained network.

    Args:
        sock -- A socket object, constructed and initialized to communicate
                over a simulated lossy network.

    Return:
        The number of bytes written to the destination.
    """
    logger = miniproject3.logging.get_logger("mp3-receiver")
    # Naive solution, where we continually read data off the socket
    # until we don't receive any more data, and then return.
    # You can do better than this!
    num_bytes = 0
    seq = b'0'
    while True:
        try:
            data = sock.recv(miniproject3.MAX_PACKET)
            head = data[:3]
            print("HEAD")
            print(head)
            if head == b'001' or b'101':
                resp = seq + b'0' + ACK
                sock.send(b'3',resp)
                logger.info("Received %d bytes", len(data))
                dest.write(data[3:])
                num_bytes += len(data)
                dest.flush()
                print(seq)
                if seq == b'1':
                    seq = b'0'
                if seq == b'0':
                    seq = b'1'
            if head == FIN:
                sock.send(FINACK)
                print("HEADER END")
                sock.close()
                break
            if not data:
                sock.send(seq + b'0' +NAK)
            
        except TimeoutError:
            sock.send(seq + b'0' +NAK)
    return num_bytes
