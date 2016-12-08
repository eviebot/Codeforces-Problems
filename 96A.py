s = raw_input()
f = False
n = 0

for i in s[:-6]:

	f = True
	if len(s) < 7:
		f = False
		break
	for j in range(0, 7):
		if s[n+j] != i:
			f = False
			break
	n +=1		
	if f == True:
		break

if f == True:
	print "YES"

if f == False:
	print "NO"