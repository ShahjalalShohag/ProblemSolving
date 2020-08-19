#include<bits/stdc++.h>
using namespace std;

int a[1 << 18];
multiset<int> f[1 << 18];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < (1 << n); i++) cin >> a[i], f[i].insert(a[i]);
 	for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask >> i & 1) {
                for (auto x: f[mask ^ (1 << i)]) {
                	f[mask].insert(x);
                	while (f[mask].size() > 2) f[mask].erase(f[mask].begin());
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
    	ans = max(ans, *f[mask].begin() + *(--f[mask].end()));
    	cout << ans << '\n';
    }
    return 0;
}	