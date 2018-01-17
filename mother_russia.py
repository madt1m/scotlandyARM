import socket
import sys

HOST = "127.0.0.1"
PORT = 12007
ETH_P_ALL = 3
with socket.socket(socket.AF_PACKET, socket.SOCK_RAW) as s:
	s.bind((HOST, PORT))
	print('Waiting for messages')
	data = s.recv(1024)
	print('Data received: '+ data)
