#!/usr/bin/python

import MySQLdb
import os
import random

# Open database connection
db = MySQLdb.connect("localhost","root","Ekartc2c5","testtimerwater" )

# prepare a cursor object using cursor() method
curs = db.cursor()

arg_list=query_string.split('&')
i=1
for arg in arg_list:
    key, value=arg.split('=')
    if i==1:    	
    	a=value
	elif i==2:
    	b=value
    elif i==3:
    	c=value
    elif i==4:
    	d=value
    i +=1

id1 = str(random.randint(1, 100000000))
devi="10001"
devt="10"
rem="1"
unit1="1"
val1="1"
try:
#t_device (id varchar(255), device_id varchar(255), device_type varchar(255), date_device varchar(255), value1 varchar(255), unit1 varchar(255), remark varchar(255), PRIMARY KEY (id))
	curs.execute("INSERT into t_device values ("+id1+", "+devi+","+devt+", now(),"+val1+","+unit1+","+rem+")")

# Commit your changes in the database
	db.commit()
	print "INSERT committed"
except:
	print "Error id1 "+id1
# disconnect from server
db.close()


