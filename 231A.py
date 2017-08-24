n = int(raw_input())
solved = 0
 
for i in range(0, n):
	s = raw_input().split()
	temp = 0
	for i in s:
 
		if i == '1':
			temp +=1
 
	if temp >=2:
		solved +=1
	temp = 0
 
print solved