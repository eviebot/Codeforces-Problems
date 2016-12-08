s = raw_input().split()
k = int(s[0])
t = int(s[1])

s = raw_input()
f = ""
while t > 0:
	n = 0
	f = ""
	while n < k-1:

		if s[n] == 'B' and s[n+1] == 'G':
			f += "GB"
			n += 2

		else:
			f += s[n]
			
			if n == k-2:
				f += s[n+1]
			n+=1
	t -= 1
	s = f
	print f


print f