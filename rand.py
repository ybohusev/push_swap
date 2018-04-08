#!/usr/bin/env python

import random

L = []

j = 1

while len(L) <= 99:
	x = random.randint(1, 100)
	for i in L:
		if (x == i):
			j = 0
	if (j == 1):
		L.append(x)
	j = 1

for x in L:
	print x,