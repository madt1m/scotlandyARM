import socket
import sys

HOST = "127.0.0.1"
PORT = 12007

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.bind((HOST, PORT))
	print('Socket created')
	s.listen(1)
	print('Waiting for connections')
	conn, addr = s.accept()
	print('Connected by' + addr)
	data = conn.recv(1024)
	print(data)
