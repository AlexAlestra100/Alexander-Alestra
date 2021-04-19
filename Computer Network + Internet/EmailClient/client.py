from socket import *
msg = '\r\n I love computer networks!'
endmsg = '\r\n.\r\n'

# Choose a mail server (e.g. Google mail server) and call it mailserver
mailsever = ('smtp.csus.edu', 25)

# Create socket called clientSocket and establish a TCP connection with mailserver
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect(mailsever)

recv = clientSocket.recv(1024).decode("utf-8")
print recv
if recv[:3] != '220':
    print '220 reply not received from server.'

# Send HELO command and print server response.
heloCommand = 'HELO Alice\r\n'
clientSocket.send(heloCommand)
recv1 = clientSocket.recv(1024).decode("utf-8")
print '\n', recv1
if recv1[:3] != '250':
    print '250 reply not received from server.'

# Send MAIL FROM command and print server response.
mfrom = 'MAIL FROM: socket3@serv.com\r\n'
clientSocket.send(mfrom)
serverRes1 = clientSocket.recv(1024).decode("utf-8")
print '\n', serverRes1

# Send RCPT TO command and print server response.
mrcpt = 'RCPT TO: aalestra@csus.edu\r\n'
clientSocket.send(mrcpt)
serverRes2 = clientSocket.recv(1024).decode("utf-8")
print '\n', serverRes2

# Send DATA command and print server response.
clientSocket.send('DATA\r\n')
serverRes3 = clientSocket.recv(1024).decode("utf-8")
print '\n', serverRes3

# Send message data.
mailmes = msg + endmsg
clientSocket.send(mailmes)
serverRes4 = clientSocket.recv(1024).decode("utf-8")
print '\n', serverRes4

# Send QUIT command and get server response.
clientSocket.send('QUIT\r\n')
serverRes5 = clientSocket.recv(1024).decode("utf-8")
print '\n', serverRes5
clientSocket.close()
