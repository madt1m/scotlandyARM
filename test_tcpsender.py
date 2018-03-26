import socket
import sys

if(sys.argc != 2):
	print("Usage: python3 test_tcpsender.py <IP>")
	exit(1)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	print('Connecting...')
	s.connect((sys.argv[1], 12007))
	s.send("PROVA".encode())


