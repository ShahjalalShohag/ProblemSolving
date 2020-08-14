#include<bits/stdc++.h>
using namespace std;

const int N = 205;
int R[N], G[N], B[N];
long long dp[N][N][N];

long long yo(int r, int g, int b) {
	int f = (r >= 0) + (g >= 0) + (b >= 0);
	if (f < 2) return 0;
	long long &ret = dp[r + 1][g + 1][b + 1];
	if (ret != -1) return ret;
	long long ans = 0;
	if (r >= 0) ans = max(ans, yo(r - 1, g, b));
	if (g >= 0) ans = max(ans, yo(r, g - 1, b));
	if (b >= 0) ans = max(ans, yo(r, g, b - 1));
	if (r >= 0 && g >= 0) ans = max(ans, R[r] * G[g] + yo(r - 1, g - 1, b));
	if (r >= 0 && b >= 0) ans = max(ans, R[r] * B[b] + yo(r - 1, g, b - 1));
	if (b >= 0 && g >= 0) ans = max(ans, B[b] * G[g] + yo(r, g - 1, b - 1));
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r, g, b; cin >> r >> g >> b;
	for (int i = 0; i < r; i++) cin >> R[i];
	for (int i = 0; i < g; i++) cin >> G[i];
	for (int i = 0; i < b; i++) cin >> B[i];
	sort(R, R + r);
	sort(G, G + g);
	sort(B, B + b);
	memset(dp, -1, sizeof dp);
	cout << yo(r - 1, g - 1, b - 1) << '\n';
    return 0;
}