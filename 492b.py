n, l = map(int, raw_input().split())
a = []
s = raw_input().split()
for i in s:
	a+= [int(i)]

a = sorted(a)
diff = []
b = 0
while b < (n-1):
	diff += [a[b+1]-a[b]]
	b += 1
if n == 1:
	diff = a
length = float(max(diff))
length /= 2 
z = float(max(a[0],l-a[n-1]))
if z > length :
	length = z
print  "%.10f" % (length)
