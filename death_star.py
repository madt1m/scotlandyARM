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
	conn = None

	try:
		print('Waiting for connections')
		conn, addr = s.accept()
		print('Connected by')
		print(addr)
		data = conn.recv(9).decode()
		print(data)

		if data == PASSWORD:  
			res = "200"
			conn.send(res.encode())
		else:
		 	res = "401"
		 	conn.send(res.encode())

		while True:
			
			data = conn.recv(1).decode()
			if data == 2:
				req = urllib.request.Request('http://api.hostip.info/get_html.php?ip=' + addr + '&position=true', headers={'User-Agent': 'Mozilla/5.0'})
				pos = urllib.request.urlopen(req).read().decode().splitlines()
				res = pos[0] + " " +  pos[3] + " " + pos[4] + " " + post[5]
			elif data == 3:

				ans = int(conn.recv(3).decode());
				
				if ans == 0:
					res = "Darth Vader"

				if ans == 1:
					res = "Darth Maul"

				if ans == 11:
					res = "Count Duku"

				if ans == 111:
					res = "Darth Sidius"

				if ans == 101:
					res = "Kylo Ren"

				
			conn.send(res.encode())
	except KeyboardInterrupt:
			s.close()


