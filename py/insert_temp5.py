#!/usr/bin/env python

import os
import cgi, cgitb
from datetime import datetime

cgitb.enable()

form = cgi.FieldStorage()
# Get data from fields
devi1 = form.getvalue('devi1')
#devt = form.getvalue('devt1')
val1 = form.getvalue('val1')
#devi = escape(devi)
#val1 = escape(val1)
#date=datetime.now().strftime('%Y-%m-%d %H:%M:%S')
#date=str(date)
#txt=devi+","+devt+","
#rem="1"
#unit1="1"
#value1="1"
try:
        f = open('/usr/lib/cgi-bin/temp5.io', 'w')
#f.write(str(devi1)+","+str(date)+","+str(val1))
        f.write(str(devi1)+","+str(val1))
        f.close()
#t_device (id varchar(255), device_id varchar(255), device_type varchar(255), d$
#       curs.execute("INSERT into t_device values("+id+","+ devi+","+devt+", no$

# Commit your changes in the database
#       db.commit()
#       html = open("calc.html".read())
        result = "<html><head>Content-Type: text/html; charset=UTF-8\n\n[("+str(devi1)+","+str(val1)+")]"
#       header = "Content-Type: text/html; charset=UTF-8\n\n"
#       output = header + html.format(result=result)
#       result "Hello World  "+str(devi1)+","+str(val1)
        print result
#       print "Content-type:text/html\r\n\r\n"
#       print "<html>"
#       print "<head><title>MyFirst CGI :) </title></head>"
#       print "<body>"
#       print "<p>It works!!!</p>"
        #for i in range(5):

#       for field in form.keys():
#               print "<tr><td>%s<td>%s" % (field, form[field].value)

        #print "<h1> hello world "+str(devi1)+" "+str(val1)
#       print "</body>"
#       print "</html>"
