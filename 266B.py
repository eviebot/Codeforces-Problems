s = raw_input().split()
n = int(s[0])
t = int(s[1])

s = raw_input()
a = []
for i in s:
	a+= [i]

while t > 0:
	j = 0
	while j < len(s)-1:
		if a[j] == 'B' and a[j+1] == 'G':
			a[j+1] = 'B'
			a[j] = 'G'
			j +=1
		j += 1

	t -= 1
t =""
for i in a:
	t += i
# test code
print t