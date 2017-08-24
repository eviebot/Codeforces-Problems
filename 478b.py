n, m = map(int, raw_input().split())

def nc2(num):
	return (num*(num-1)/2)
# for minimun 
q = n/m
r = n % m
mini = (nc2(q)*(m-r)) + (nc2(q+1) * r)

maxi = nc2(n-m+1)
print mini, maxi