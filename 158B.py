
n = int(raw_input())
cars = 0
s = raw_input().split()
s1 = 0
s2 = 0
s3 = 0

for i in s:
	i = int(i)
	if i == 1:
		s1 +=1
	elif i == 2:
		s2 +=1
	elif i == 3:
		s3 +=1
	elif i == 4:
		cars +=1

if s3 >= s1:
	cars += s3
	s1 = 0
elif s1 > s3:
	cars += s3
	s1 -= s3

cars += s1/4 + s2/2

if s1% 4 ==0:
	cars += s2 % 2

elif s1 % 4 == 3:
	cars += 1 + s2 % 2

elif s1 % 4 == 1 or s1 % 4 ==2:
	cars += 1
print cars

