#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int f[N][40], a[N][40];
long long s[N][40];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	long long m; cin >> m;
	for (int i = 0; i < n; i++) cin >> f[i][0];
	for (int i = 0; i < n; i++) cin >> s[i][0], a[i][0] = s[i][0];
	for (int k = 1; k < 40; k++) {
		for (int i = 0; i < n; i++) {
			f[i][k] = f[f[i][k - 1]][k - 1];
			s[i][k] = s[i][k - 1] + s[f[i][k - 1]][k - 1];
			a[i][k] = min(a[i][k - 1], a[f[i][k - 1]][k - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		int cur = i;
		long long sum = 0;
		int mn = 1e9;
		for (int k = 0; k < 40; k++) {
			if (m >> k & 1) {
				sum += s[cur][k];
				mn = min(mn, a[cur][k]);
				cur = f[cur][k];
			}
		}
		cout << sum << ' ' << mn << '\n';
	}
    return 0;
}