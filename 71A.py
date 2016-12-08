n= int(raw_input())

S = []
for i in range(0, n):
	s = raw_input()
	if len(s) > 10:
		s= s[0]+`len(s[1:-1])`+s[-1]
	S += [s]

for i in S:
	print i