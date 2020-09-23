dp = {}
def yo(a, b, i, j):
	if min(a, b, i, j) < 0: return 0
	if a == 0 and b == 0: return 1
	x = (a, b, i, j)
	if x not in dp: dp[x] = (yo(a - 1, b, i - 1, k2) + yo(a, b - 1, k1, j - 1)) % 10 ** 8
	return dp[x]
a, b, k1, k2 = map(int, input().split());
print(yo(a, b, k1, k2))
