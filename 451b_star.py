n  =int(raw_input())
a = map(int, raw_input().split())

start = -1
end = -1
i = 0
f = True
g = True
while i < n -1 and g:
	if a[i+1] < a[i] and f:
		start = i
		f = False
	if (not f) and a[i+1] > a[i]:
		end = i
		g = False
	i += 1
if end == -1:
	end = n-1
c = a[start:end+1]
c.reverse()
b = a[0:start] +c + a[end+1:]
if f == True:
	print "yes"
	print "1 1"
elif sorted(a) == b and (not f):
	print "yes"
	print `(start+1)`+" "+`(end+1)`
else:
	print "no"