#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, k; cin >> a >> b >> c >> k;
	int ans = 0;
	ans += min(a, k); k -= min(a, k);
	k -= min(k, b);
	ans -= min(k, c);
	cout << ans << '\n';
    return 0;
}