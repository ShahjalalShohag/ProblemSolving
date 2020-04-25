#include<bits/stdc++.h>
using namespace std;

const int N = 105, mod = 998244353;

int X, Y;
vector<pair<int, int>> b;
int a[N], dp[2][2][10][10][16][16][N];
int yo (int i, int cx, int cy, int mx, int my, int zx, int zy) {
	if (i < 0) {
		if (cx || cy || zx || zy) return 0;
		return (mx & my) > 0;
	}
	int &ret = dp[zx][zy][cx][cy][mx][my][i];
	if (ret != -1) return ret;
	int ans = 0;
	for (int k = 0; k < 10; k++) {
		int nwx = k * X + cx, nwy = k * Y + cy;
		int nmx = mx, nmy = my;
		for (int j = 0; j < b.size(); j++) {
			if (nwx % 10 == b[j].first) nmx |= 1 << j;
			if (nwy % 10 == b[j].second) nmy |= 1 << j;
		}
		int nzx = zx;
		if (nwx % 10 < a[i]) nzx = 0;
		if (nwx % 10 > a[i]) nzx = 1;	
		int nzy = zy;
		if (nwy % 10 < a[i]) nzy = 0;
		if (nwy % 10 > a[i]) nzy = 1;
		ans += yo(i - 1, nwx / 10, nwy / 10, nmx, nmy, nzx, nzy);
		if (ans >= mod) ans -= mod;
	}
	return ret = ans;
}
int32_t main() {
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';
    int ans = 0;
    for (int x = 1; x <= 9; x++) {
    	for (int y = 1; y <= 9; y++) {
    		if (x != y && __gcd(x, y) == 1) {
    			b.clear(); X = x; Y = y;
    			for (int k = 1; k <= 4; k++) {
    				if (x * k <= 9 && y * k <= 9) {
    					b.push_back({x * k, y * k});
    				}
    			}
    			memset(dp, -1, sizeof dp);
    			ans += yo(n - 1, 0, 0, 0, 0, 0, 0);
    			if (ans >= mod) ans -= mod;
    		}
    	}
    }
    int val = 0;
    for (int i = 0; i < n; i++) val = (val * 10LL % mod + a[i]) % mod;
    ans = (ans + val) % mod;
	cout << ans << '\n';
    return 0;
}