n = int(raw_input())
rem_sum = 0

s = raw_input().split()
a = []
for i in s:
	a += [int(i)]
	rem_sum += int(i)


a = sorted(a, reverse= True)

coins = 0
my_sum = 0
n = 0
while n < len(a):
	my_sum += a[n]
	rem_sum -= a[n]
	coins += 1
	if my_sum > rem_sum:
		break

	n+=1
print coins