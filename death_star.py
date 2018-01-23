import socket
import sys
import urllib

#HOST = "localhost"
PORT = 12007
PASSWORD = "lllduldul"

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
		res = "200"
		conn.send(res.encode())
	else:
	 	res = "401"
	 	conn.send(res.encode())
	while 1:
		data = conn.recv(8)
		if data == 2:
			res = urllib.urlopen('http://api.hostip.info/get_html.php?ip=' + 'addr' + '&position=true').read()
			conn.send(res.encode())
		elif data[0] == 3:
			if data[1] == 1 and data[2] == 2
				res = ""
				conn.send(res.encode())
			if data[1] == 1 and data[2] == 2
				res = ""
				conn.send(res.encode())
			if data[1] == 1 and data[2] == 2
				res = ""
				conn.send(res.encode())
			if data[1] == 1 and data[2] == 2
				res = ""
				conn.send(res.encode())
			if data[1] == 1 and data[2] == 2
				res = ""
				conn.send(res.encode())
			
		#conn.close()


