a,b = map(int, input().split())
if b-a >=5:
	print('0')
else:
	ans = 1
	for i in range(a+1, b+1):
		ans = ans*i
	print(str(ans)[-1])