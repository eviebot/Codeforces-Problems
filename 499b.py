n, m = map(int, raw_input().split())
word_dict = {}

for i in range(0, m):
	s1, s2 = raw_input().split()
	word_dict[s1] = s2

c = raw_input().split()
for i in c:
	s2 = word_dict[i]
	if len(i) <= len(s2):
		print i,
	else:
		print s2,