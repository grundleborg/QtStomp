# Opens a socket and writes to standard out whatever it sees.

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('127.0.0.1', 12098))
s.listen(1)

(conn, addr) = s.accept()
print("Received Connection from address: " + str(addr))

buf = b""

while 1:
    print("Looped")
    data = conn.recv(20)
    if not data: 
        print ("Received Data:")
        print (buf.decode("utf-8"))
        break
    buf += data

conn.close()


