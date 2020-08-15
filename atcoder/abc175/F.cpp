#include<bits/stdc++.h>
using namespace std;

const int N = 55;
const long long inf = 2e18;

string s[N];
int c[N], n;
long long dp[N][22][22][2];

long long yo(int k, int st, int en, int f) {
	string nw = s[k].substr(st, en - st + 1);
	string tmp(nw.rbegin(), nw.rend());
	long long &ans = dp[k][st][en][f];
	if (nw == tmp) return ans = 0;
	if (ans != -1) return ans;
	ans = inf;
	for (int i = 1; i <= n; i++) {
		int sz = min(en - st + 1, (int)s[i].size());
		if (f) {
			string X = s[k].substr(st, sz);
			string Y = s[i].substr((int)s[i].size() - sz);
			reverse(Y.begin(), Y.end());
			if (X == Y) {
				long long cur = c[i];
				if (en - st + 1 > sz) {
					cur += yo(k, st + sz, en, 1);
				}
				if (s[i].size() > sz) {
					cur += yo(i, 0, (int)s[i].size() - sz - 1, 0);
				}
				ans = min(ans, cur);
			}
		}
		else {
			string X = s[k].substr(en - sz + 1, sz);
			string Y = s[i].substr(0, sz);
			reverse(X.begin(), X.end());
			if (X == Y) {
				long long cur = c[i];
				if (en - st + 1 > sz) {
					cur += yo(k, 0, en - sz, 0);
				}
				if (s[i].size() > sz) {
					cur += yo(i, sz, (int)s[i].size() - 1, 1);
				}
				ans = min(ans, cur);
			}
		}
	}
	return ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	long long ans = inf;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> c[i];
	}
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= n; i++) {
		ans = min(ans, 1LL * c[i] + yo(i, 0, (int)s[i].size() - 1, 0));
		ans = min(ans, 1LL * c[i] + yo(i, 0, (int)s[i].size() - 1, 1));
	}
	if (ans == inf) ans = -1;
	cout << ans << '\n';
    return 0;
}