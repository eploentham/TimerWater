#!/usr/bin/python

import MySQLdb
import os
import cgi, cgitb
import random
# Open database connection
db = MySQLdb.connect("localhost","root","Ekartc2c5","testtimerwater" )
# prepare a cursor object using cursor() method
curs = db.cursor()

#query_string=os.environ["QUERY_STRING"]

# Create instance of FieldStorage
form = cgi.FieldStorage()
# Get data from fields
devi = form.getvalue('devi')
devt = form.getvalue('devt')
dist = form.getvalue('dist')

#arg_list=query_string.split('&')
i=1
value1=2
#dist="6"

#print len(arg_lost)

#for arg in arg_list:
#       key, value1=arg.split('=')
#       if i==1 :
#               devi=value1
#       elif i==2 :
#               devt=value1
#       elif i==3 :
 #              dist=value1
#       elif i==4 :
#               d=value1
i +=1

id = str(random.randint(1,999999999))

#devi="10001"
#devt="10"
rem="1"
unit1="1"
#value1="1"
try:
#t_device (id varchar(255), device_id varchar(255), device_type varchar(255), date_device varchar(255), value1 varchar(255), unit1 varchar(255), remark varchar(255))
        curs.execute("INSERT into t_device values("+id+","+ devi+","+devt+", now(),"+dist+","+unit1+","+rem+")")

# Commit your changes in the database
        db.commit()
        print "INSERT committed"
except:
        print "Error id "+id
# disconnect from server
db.close()
