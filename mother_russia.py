import socket
import sys

#HOST = "localhost"
PORT = 80
PASSWORD = "uurrddll"

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.bind(('', PORT))
	print('Socket created')
	s.listen(1)
	print('Waiting for connections')
	conn, addr = s.accept()
	print('Connected by')
	print(addr)
	data = conn.recv(8)
	print(data.decode())
	if data == PASSWORD:  
		res = bytes.fromhex('FF')
		conn.send(res)
	else:
	 	res = bytes.fromhex('00')
	 	conn.send(res)
	conn.close()


