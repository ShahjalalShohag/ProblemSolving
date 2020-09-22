import sys
input = sys.stdin.buffer.readline
n = int(input())
a = list(map(int, input().split()))
cnt = [0] * (n + 2)
vis1 = [0] * (n + 2)
vis2 = [0] * (n + 2)
for i in a: 
	cnt[i] += 1
mn, mx = 0, 0
for i in range(1, n + 1):
	if (cnt[i] == 0):
		continue
	if (vis1[i - 1] == 0 and vis1[i] == 0):
		vis1[i + 1] = 1
		mn += 1
	for k in range(3):
		if (vis2[i + k - 1] == 0 and cnt[i] > 0):
			mx += 1
			vis2[i + k - 1] = 1;
			cnt[i] -= 1
print(mn, mx)