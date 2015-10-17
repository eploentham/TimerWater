#!usr/bin/python
import os
#import glob

path="/usr/lib/cgi-bin/"
filename=""
dirs=os.listdir(path)
try:
	for filename in dirs:
		#f=open(filename,'r')
		if filename.endswith(".sensor"):
			f=open(path+filename,'r')
			#str1=f.read()
			sensor1=str(f.read()).split(',')
			#for str11 in str1:
			print "filename "+sensor1[0]

			f.close()
		#f.close()
	#f.read()
	#f.close()
	
except Exception, e:
	raise
else:
	pass
finally:
	pass