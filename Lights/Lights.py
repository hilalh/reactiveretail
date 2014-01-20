
color = " "
att = " "





while age != 120:

	# addressing information of target
	IPADDR = '10.10.100.255'
	PORTNUM = 8899

	# enter the data content of the UDP packet as hex
	if (age < arrive): color = "purple"	
	elif ((age > arrive) & (age <= early)):
		if (att == "positive"): color = "blue"
		elif (att == "negative"): color = "red"
		else: color = "yellow"
	elif ((age > early) & (age <= medium)):
		if (att == "positive"): color = "green"
		elif (att == "negative"): color = "red"
		else: color = "blue"
	elif ((age > medium) & (age <= late)):
		if (att == "positive"): color = "green"
		elif (att == "negative"): color = "red"
		else: color = "green"
	else: color = "purple"
	
	
	if (color=="purple"):PACKETDATA='20bf55'.decode('hex')
	elif (color=="blue"):PACKETDATA='20ff55'.decode('hex')
	elif (color=="yellow"):PACKETDATA='207f55'.decode('hex')
	elif (color=="green"):PACKETDATA='206f55'.decode('hex')
	elif (color== "orange"):PACKETDATA='208f55'.decode('hex')
	elif (color== "red"):PACKETDATA='209f55'.decode('hex')
	else: PACKETDATA='209f55'.decode('hex')


	# initialize a socket, think of it as a cable
	# SOCK_DGRAM specifies that this is UDP
	s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)

	# connect the socket, think of it as connecting the cable to the address location
	s.connect((IPADDR, PORTNUM))

	# send the command
	s.send(PACKETDATA)

	# close the socket
	s.close()
	time.sleep(1.0)

