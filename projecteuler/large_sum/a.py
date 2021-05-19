#!/usr/bin/env python3

sum = 0
for i in range(100):
	sum += int(input())
print(sum)
s = str(sum)
for i in range(10):
	print(s[i])