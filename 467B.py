s = raw_input().split()
n = int(s[0])
m = int(s[1])
k = int(s[2])
j = []
friends = 0
for i in range(0, m+1):
	x = int(raw_input())
	s = ""
	f = ""
	while x != 1:
		s += `x%2`
		x /=2

	for i in range(0, n-len(s)-1):
		f += '0'
	s1 = '1' + s[::-1]
	j += [f+s1]

for i in j[:-1]:
	count = 0
	c1 = 0
	while count < n:
		if i[count] != j[-1][count]:
			c1 += 1
		count += 1

	if c1 <= k:
		friends +=1

print friends