#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int a[50][50][10];

pair<int, int> yo(long long n) {
	int p2 = 0;
	while (n % 2 == 0) p2++, n /= 2;	
	int p5 = 0;
	while (n % 5 == 0) p5++, n /= 5;
	return {p2, p5};
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		long long cur = 0;
		int d = 0, f = 0;
		for (auto i: s) {
			if (i == '.') {
				f = 1;
				continue;
			}
			cur = cur * 10 + i - '0';
			d += f;
		}
		auto p = yo(cur);
		a[p.first][p.second][d]++;
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			for (int x = 0; x < 10; x++) {
				if (a[i][j][x] == 0) continue;
				for (int k = 0; k < 50; k++) {
					for (int l = 0; l < 50; l++) {
						for (int y = 0; y < 10; y++) {
							int d = min(i + k, j + l);
							if (x + y <= d) {
								if (i == k && j == l && x == y) {
									ans += 1LL * a[i][j][x] * (a[i][j][x] - 1);
								}
								else ans += 1LL * a[i][j][x] * a[k][l][y];
							}
						}
					}
				}
			}
		}
	}
	cout << ans / 2 << '\n';
    return 0;
}