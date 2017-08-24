s = raw_input()
g = ""
s = s.lower()
i = 0
while i < len(s):
	a = s[i]
	if not (a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u' or a =='y'):
		g += '.'+a

	i +=1


print g