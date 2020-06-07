#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int pos[N];
map<int, int> mp;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k; pos[k] = i;
	}
	for (int i = 0; i < n; i++) {
		int k; cin >> k; mp[(i - pos[k] + n) % n]++;
	}
	int ans = 0;
	for (auto x: mp) ans = max(ans, x.second);
	cout << ans << '\n';
    return 0;
}