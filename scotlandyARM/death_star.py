import socket
import sys
import urllib.request

if(len(sys.argv) != 2):
	print("Specify port!")
	exit(1)
#HOST = "localhost"
PORT = int(sys.argv[1])
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
			
			data = conn.recv(1)
			print("ricevuto")
			print(data)

			if ord(data) == 1:
				print("request 2 received")
				'''
				req = urllib.request.Request('http://api.hostip.info/get_html.php?ip=' + '172.20.238.136' + '&position=true', headers={'User-Agent': 'Mozilla/5.0'})
				pos = urllib.request.urlopen(req).read().decode().splitlines()
				'''
				url = "http://api.hostip.info/get_html.php?ip=" + '172.20.238.136' + "&position=true"
				print(url)
				headers = {'User-Agent' : 'Mozilla/5.0'}
				req = urllib.request.Request(url, headers = headers)
				print(req)
				pos = urllib.request.urlopen(req)
				print(pos)
				pos = pos.read()
				print(pos)
				pos = pos.decode()
				print(pos)
				pos = pos.splitlines()
				print(pos)
				'''
				res = pos[0] + " " +  pos[3] + " " + pos[4] + " " + pos[5]
				'''
				res = 'Country: European Union(EU) City: (Unknown City) IP: 130.192.27.17'
				conn.send(res.encode())
				print(res)
				print("data sent back")
			
			elif ord(data) == 2:
				print("request 3 received")
				ans = conn.recv(3);
				#ans = int.from_bytes(ans, byteorder='big', signed=False)
				print(ans)
				
				if ans == b'\x00\x00\x00':
					res = "Darth Vader. That's impossible. I AM DARTH VADER! <force choke over the wire>"

				elif ans == b'\x00\x01\x00':
					res = "Darth Maul! How do you feel about those tiny little horns?"

				elif ans == b'\x01\x01\x00':
					res = "Count Duku! Definitely a man with his head right on shoulders."

				elif ans == b'\x01\x00\x00':
					res = "Darth Sidius. UNLIMITED POWER! THUNDER! NANANANAA NANANAA NAA"

				elif ans == b'\x00\x00\x01':\
					res = "...kylo ren. Feel sorry about that. You'll eventually get past adolescence, bru."
				
				else: 
					res = "Yoda, the fake master...how did you get the device? YOU WILL BE EXECUTED!"


				conn.send(res.encode())
				print(res)
				print("data sent back")
			


	except KeyboardInterrupt:
			s.close()


