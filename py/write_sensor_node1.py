#!/usr/bin/python

import os
import cgi, cgitb
from datetime import datetime

form = cgi.FieldStorage()
# Get data from fields
devi1 = form.getvalue('devi1')
#devt = form.getvalue('devt1')
val1 = form.getvalue('val1')
date=datetime.now().strftime('%Y-%m-%d %H:%M:%S')
#date=str(date)
#txt=devi+","+devt+","
rem="1"
unit1="1"
#value1="1"
try:
        f = open('/usr/lib/cgi-bin/sensor_node1.io', 'w')
#f.write(str(devi1)+","+str(date)+","+str(val1))
        f.write(devi1+","+val1)
        f.close()
#t_device (id varchar(255), device_id varchar(255), device_type varchar(255), d$
#       curs.execute("INSERT into t_device values("+id+","+ devi+","+devt+", no$

# Commit your changes in the database
#       db.commit()
        print "INSERT committed"
except:
        print "Error id "+id
# disconnect from server
#db.close()
