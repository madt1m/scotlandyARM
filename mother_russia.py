import socket
import sys

#HOST = "localhost"
PORT = 12007
PASSWORD = "uuuuuuuu"

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
	if data == PASSWORD.strip():  
		res = "password corretta"
		conn.send(res.encode())
	else:
	 	res = "password errata, autodistruzione imminente"
	 	conn.send(res.encode())
	conn.close()


