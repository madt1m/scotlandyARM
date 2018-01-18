import socket
import sys


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	print('Connecting...')
	s.connect(("172.20.238.243", 80))
	s.send("PROVA".encode())


