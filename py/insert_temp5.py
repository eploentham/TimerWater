#!/usr/bin/env python

import os
import cgi, cgitb
import ConfigParser
from datetime import datetime

cgitb.enable()

form = cgi.FieldStorage()
# Get data from fields
devi1 = form.getvalue('devi1')
nodemcuid = form.getvalue('nodemcuid')
val1 = form.getvalue('val1')
#devi = escape(devi)
#val1 = escape(val1)
#date=datetime.now().strftime('%Y-%m-%d %H:%M:%S')
#date=str(date)
#txt=devi+","+devt+","
try:
        f = open('/usr/lib/cgi-bin/temp5.io', 'w')
#f.write(str(devi1)+","+str(date)+","+str(val1))
        f.write(str(devi1)+","+str(val1))
        f.close()
#t_device (id varchar(255), device_id varchar(255), device_type varchar(255), d$
#       curs.execute("INSERT into t_device values("+id+","+ devi+","+devt+", no$
        config = ConfigParser.ConfigParser()
        config.read('/home/ekapop/build-timerwater-Desktop_Qt_5_5_0_GCC_64bit-Debug/timerwater.ini')
        ipfaucetnodemcu = config.get(devi1,'ipfaucetnodemcu')
        ippumpnodemcu = config.get(devi1,'ippumpnodemcu')
        portfaucet = config.get(devi1,'portfaucet')
        portpump = config.get(devi1,'portpump')
        max1 = config.get(devi1,'max')
        min1 = config.get(devi1,'min')

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
        if(os.path.isfile(nodemcuid+".io")):
                f = open(nodemcuid+".io", 'r')
                aaa = f.readline()
                bbb = aaa.split(',')
                f.close()

        #if(int(val1)>80): val1="ON"
        #else: val1="OFF"
        result = "<html><head>Content-Type: text/html; charset=UTF-8\n\n[("+str(devi1)+","+str(val1)+";)]"
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

