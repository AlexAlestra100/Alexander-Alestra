#!/usr/bin/env python3
from scapy.all import *

# Construct the request
Qdsec = DNSQR(qname='twysw.example.com')
dns = DNS(id=0xAAAA, qr=0, qdcount=1, ancount=0, nscount=0, arcount=0, qd=Qdsec)
ip = IP(dst='10.9.0.53', src='10.9.0.2')
udp = UDP(dport=53, sport=33333, chksum=0)
request = ip/udp/dns

# Save the packet to a file
with open('ip_req.bin', 'wb') as f:
   f.write(bytes(request))