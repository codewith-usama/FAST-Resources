import socket
import hashlib
import struct
import sys
import binascii

UDP_IP = "127.0.0.1"
UDP_Port = 5009

UDP_Packet_Data = struct.Struct('I I 8s 32s')
clientUnpacker = struct.Struct('I I 32s')

ACK = 0
SEQ = 0

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

dataList = ['20P-0648', '20K-0190']

for data in dataList:
    dataByte = data.encode()

    values = (ACK, SEQ, dataByte)
    UDP_Data = struct.Struct('I I 8s')
    chkSum_Data = (UDP_Data.pack(*values))
    chkSum = bytes(hashlib.md5(chkSum_Data).hexdigest(), encoding="UTF-8")

    values = (ACK, SEQ, dataByte, chkSum)
    UDP_Packet = UDP_Packet_Data.pack(*values)

    print("Sending Packet...")
    Flag = True
    while Flag == True:
        try:
            currentACK=ACK
            sock.sendto(UDP_Packet, (UDP_IP, UDP_Port))
            print("Packet Sent!\n")

            responseSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            responseSocket.settimeout(0.009)
            responseSocket.bind((UDP_IP, 5004))

            print("Receiving Server Response...")
            p_size=1024
            rData, addr = responseSocket.recvfrom(p_size)
            rPacket = clientUnpacker.unpack(rData)

            rACK = rPacket[0]
            if currentACK != rACK:
                print("\nPrinting Server Response...")
                print(rPacket[0], rPacket[1], rPacket[2], "\n")
                print("Data Corrupted")
                continue
            else:
                print("\nPrinting Server Response...")
                print(rPacket[0], rPacket[1], rPacket[2], "\n")
                print("Data not corrupted\n")
                correctRespSequence = rPacket[1]
                break

            Flag = False
        except socket.timeout:
            Flag = True
            print("Server response timeout occurred... trying again\n")
            print("-----------------------------------------------------------------------------")
            continue

    SEQ = correctRespSequence
    if ACK == 0:
        ACK = 1
    else:
        ACK = 0

    print("-----------------------------------------------------------------------------")

sock.close()
responseSocket.close()
