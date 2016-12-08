n = int((raw_input().split())[0])
t = 0
m = 1

s = raw_input().split()

#for i in s:
#	a += [int(i)]

for i in s:
	i = int(i)
	if i >= m:
		t += (i-m)


	else:
		t += (n - (m - i))
	m = i	

print t