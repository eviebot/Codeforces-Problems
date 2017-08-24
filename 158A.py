a = []
partici = 0
s = raw_input().split()
n = int(s[0])
k = int(s[1]) - 1   # to get correct index
s = raw_input().split()

for i in s:
	a += [int(i)]   # list of scores in descending order created 

k1 = k    #to check if scores at kth index are equal
for i in a[k+1:]:
	if i == a[k]:
		k1 += 1
	else:
		break

for i in a[:k1+1]:
	if i > 0:
		partici +=1

print partici