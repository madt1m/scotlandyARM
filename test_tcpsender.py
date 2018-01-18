import socket
import sys


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	print('Connecting...')
	s.connect(("172.20.238.243", 12007))
	s.send("PROVA".encode())


