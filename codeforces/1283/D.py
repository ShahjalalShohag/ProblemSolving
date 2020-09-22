n, m = map(int, input().split())
a = list(map(int, input().split()))
mp = {}
q = []
for i in a:
	q.append(i)
	mp[i] = 0
ans, res, i = [], 0, 0
while (len(ans) < m):
	x = q[i]
	for k in [-1, 1]:
		if (x + k not in mp):
			mp[x + k] = mp[x] + 1
			res += mp[x + k]
			q.append(x + k)
			ans.append(x + k)
		if (len(ans) == m):
			break;
	i += 1
print(res)
print(*ans)


