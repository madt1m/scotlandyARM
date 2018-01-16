import socket
import sys

HOST = None
PORT = 12007

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.bind(HOST, PORT)
	s.listen(1)
	conn, addr = s.accept()
	with conn:
		print('Connected by', addr)
		while True:
			data = conn.recv(1024)
			if not data:break
			print('Data received: '+ data)