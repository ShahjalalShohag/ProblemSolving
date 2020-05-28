#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

void build(int n, vector<int> &a, vector<vector<int>> &t) {
    for(int i = 1; i <= n; ++i) t[i][0] = a[i];
    for(int k = 1; k < 18; ++k) {
        for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
            t[i][k] = max(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
        }
    }
}
int query(vector<vector<int>> &t, int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return max(t[l][k], t[r - (1 << k) + 1][k]);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n + 1, 0), s(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	vector<vector<int>> t1(n + 1, vector<int>(18, 0)), t2(n + 1, vector<int>(18, 0));
	build(n, a, t1);
	build(n, s, t2);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cur = i;
		while (cur <= n) {
			int l = cur, r = n, st = query(t1, i, cur), nw = cur;
			while (l <= r) {
				int mid = l + r >> 1;
				if (query(t1, i, mid) == st) {
					nw = mid; l = mid + 1;
				}
				else r = mid - 1;
			}
			ans = max(ans, query(t2, cur, nw) - s[i - 1] - st);
			cur = nw + 1;
		}
	}
	cout << ans << '\n';
    return 0;
}