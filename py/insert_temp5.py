#!/usr/bin/env python

import os,sys
import cgi, cgitb
import ConfigParser
from datetime import datetime

cgitb.enable()



form = cgi.FieldStorage()
# Get data from fields
devi1 = form.getvalue('devi1')
nodemcuid = form.getvalue('nodemcuid')
val1 = form.getvalue('val1')
path="/usr/lib/cgi-bin/"
fileini='/home/pi/timerwater-build-desktop-Qt_4_8_2__System__Release/timerwater.ini'
#devi = escape(devi)
#val1 = escape(val1)
#date=datetime.now().strftime('%Y-%m-%d %H:%M:%S')
#date=str(date)
#txt=devi+","+devt+","
try:
	f = open('/usr/lib/cgi-bin/temp5.io', 'w')
#f.write(str(devi1)+","+str(date)+","+str(val1))
<<<<<<< HEAD
	f.write(str(devi1)+","+str(val1)+","+str(nodemcuid))
	f.close()
=======
        f.write(str(devi1)+","+str(val1)+","+str(nodemcuid))
        f.close()
>>>>>>> origin/master
#t_device (id varchar(255), device_id varchar(255), device_type varchar(255), d$
#       curs.execute("INSERT into t_device values("+id+","+ devi+","+devt+", no$
	config = ConfigParser.ConfigParser()
	if(not os.path.isfile(fileini)):
		print "sss"

	config.read(fileini)
<<<<<<< HEAD
	ipfaucetnodemcu = config.get(devi1,'ipfaucetnodemcu')
	ippumpnodemcu = config.get(devi1,'ippumpnodemcu')
	portfaucet = config.get(devi1,'portfaucet')
	portpump = config.get(devi1,'portpump')
	max1 = config.get(devi1,'max')
	min1 = config.get(devi1,'min')
	
	chk="-"
#	if not(ipfaucetnodemcu=="") & not(ippumpnodemcu==""):
	if (ipfaucetnodemcu !="") & (ippumpnodemcu !=""):
#		if not ippumpnodemcu !="":
		chk=ipfaucetnodemcu
		if(ipfaucetnodemcu==ippumpnodemcu):
#			chk="rrrrr"
			f = open(ipfaucetnodemcu+".io", 'r')
			for aa in f:
                                oldperiod = aa.split(',')
				chk=oldperiod[0]
			f.close()
			
			if int(val1)>=int(max1):
				f = open(ipfaucetnodemcu+".io", 'w')
				f.write(portfaucet+",ON\n")
				f.write(portpump+",ON\n")
				f.close()
			elif int(val1)<=int(min1):
#					if int(val1) >= int(min1):
				f = open(ipfaucetnodemcu+".io", 'w')
				f.write(portfaucet+",OFF\n")
				f.write(portpump+",OFF\n")
				f.close()
		else:
#			chk="gggg"
			f = open(ipfaucetnodemcu+".io", 'w')
			if int(val1)>=int(max1):
				f.write(portfaucet+",ON\n")
			else:
				f.write(portfaucet+",OFF\n")
=======
        ipfaucetnodemcu = config.get(devi1,'ipfaucetnodemcu')
        ippumpnodemcu = config.get(devi1,'ippumpnodemcu')
        portfaucet = config.get(devi1,'portfaucet')
        portpump = config.get(devi1,'portpump')
        max1 = config.get(devi1,'max')
        min1 = config.get(devi1,'min')
	
	chk="-"
        if not(ipfaucetnodemcu=='') & (ippumpnodemcu==""):
		chk="ipfaucetnodemcu"
		if(ipfaucetnodemcu==ippumpnodemcu):
                	f = open(ipfaucetnodemcu+".io", 'w')
                	if int(val1)>=int(max1):
                    		f.write(portfaucet+",ON\n")
                    		f.write(portpump+",ON\n")
                	else:
                    		f.write(portfaucet+",OFF\n")
                    		f.write(portpump+",OFF\n")
                	f.close()
            	else:
                	f = open(ipfaucetnodemcu+".io", 'w')
                	if int(val1)>=int(max1):
                    		f.write(portfaucet+",ON\n")
                	else:
                    		f.write(portfaucet+",OFF\n")
>>>>>>> origin/master
			f.close()
			f = open(ippumpnodemcu+".io", 'w')
			if int(val1)>=int(max1):
				f.write(portpump+",ON\n")
			else:
				f.write(portpump+",OFF\n")
			f.close()
#	ippumpnodemcu=''
#	ipfaucetnodemcu=''
	if not ippumpnodemcu:
		f = open(ippumpnodemcu+".io", 'w')
		if int(val1)>=int(max1):
			f.write(portpump+",ON\n")
		else:
			f.write(portpump+",OFF\n")
		f.close()
	if not ipfaucetnodemcu:
		f = open(ipfaucetnodemcu+".io", 'w')
		if int(val1)>=int(max1):
			f.write(portfaucet+",ON\n")
		else:
			f.write(portfaucet+",OFF\n")
		f.close()
	aaa="-"
	bbbb=""
	if(os.path.isfile(nodemcuid+".io")):
<<<<<<< HEAD
#		chk="nodemcuid";
=======
>>>>>>> origin/master
		f = open(nodemcuid+".io", 'r')
		for aaa in f:
#		aaa = f.readlines()
			bbb = aaa.split(',')
			bbbb+=bbb[0]+","+bbb[1]+";"
		f.close()

        #if(int(val1)>80): val1="ON"
        #else: val1="OFF"
<<<<<<< HEAD
#        result = "<html><head>Content-Type: text/html; charset=UTF-8\n\n[("+str(bbb[0])+";)]"
	result = "<html><head>Content-Type: text/html; charset=UTF-8\n\n[("+str(bbbb)+")]"
#	result = "<html><head>Content-Type: text/html; charset=UTF-8\n\n[("+str(nodemcuid)+")]"
=======
#        result = "<html><head>Content-Type: text/html; charset=UTF-8\n\n[("+str(bbb[0])+","+str(bbb[1])+";)]"
        result = "<html><head>Content-Type: text/html; charset=UTF-8\n\n[("+str(bbbb)+")]"
>>>>>>> origin/master
#       header = "Content-Type: text/html; charset=UTF-8\n\n"
#       result "Hello World  "+str(devi1)+","+str(val1)
        print result
#       print "Content-type:text/html\r\n\r\n"
        #for i in range(5):

#       for field in form.keys():
#               print "<tr><td>%s<td>%s" % (field, form[field].value)
        #print "<h1> hello world "+str(devi1)+" "+str(val1)
#       print "</body>"
#       print "</html>"
        #print (result)
except:
        print "Error id "+id
# disconnect from server
#db.close()


