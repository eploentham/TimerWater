import os
import cgi, cgitb
import ConfigParser
from datetime import datetime

cgitb.enable()

val1=80

config = ConfigParser.ConfigParser()
if(os.path.isfile('/home/ekapop/build-timerwater-Desktop_Qt_5_5_0_GCC_64bit-Debug/timerwater.ini')): print "aaa"
config.read('/home/ekapop/build-timerwater-Desktop_Qt_5_5_0_GCC_64bit-Debug/timerwater.ini')
ipfaucetnodemcu = config.get('Sensor1','ipfaucetnodemcu')
ippumpnodemcu = config.get('Sensor1','ippumpnodemcu')
portfaucet = config.get('Sensor1','portfaucet')
portpump = config.get('Sensor1','portpump')
max1 = config.get('Sensor1','max')
min1 = config.get('Sensor1','min')

data1="-"
data2="-"

if(not(ipfaucetnodemcu=="")&(ippumpnodemcu=="")):
    if(ipfaucetnodemcu==ippumpnodemcu):
        f = open(ipfaucetnodemcu+".io", 'w')
        if(int(val1)>=max1):
            f.write(portfaucet+",ON")
            f.write(portpump+",ON")
        else:
            f.write(portfaucet+",OFF")
            f.write(portpump+",OFF")
        f.close()
    else:
        f = open(ipfaucetnodemcu+".io", 'w')
        if(int(val1)>=max1):
            f.write(portfaucet+",ON")
        else:
            f.write(portfaucet+",OFF")
        f.close()
        f = open(ippumpnodemcu+".io", 'w')
        if(int(val1)>=max1):
            f.write(portpump+",ON")
        else:
            f.write(portpump+",OFF")
        f.close()

    
if(ippumpnodemcu!=""):
    f = open(ippumpnodemcu+".io", 'w')
    if(int(val1)>=max1):
        f.write(portpump+",ON")
    else:
        f.write(portpump+",OFF")
    f.close()
if(ipfaucetnodemcu!=""):
    f = open(ipfaucetnodemcu+".io", 'w')
    if(int(val1)>=max1):
        f.write(portfaucet+",ON")
    else:
        f.write(portfaucet+",OFF")
    f.close()
if(os.path.isfile(ippumpnodemcu+".io")):
	f = open(ippumpnodemcu+".io", 'r')
	aaa = f.readline()
	bbb = aaa.split(',')
	#ccc = aaa.split(',',1)
	f.close()   
	print bbb[0]
	print bbb[1]
#
#	vvv
