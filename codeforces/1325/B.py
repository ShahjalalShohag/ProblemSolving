import sys
I = sys.stdin.buffer.readline
for _ in range(int(I())):
	I(); print(len(set(I().split())))