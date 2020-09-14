#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

long long h[N], a[N], b[N];
vector<int> pos[N];
map<long long, int> mp;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = rnd();
		b[i] = rnd();
	}
	long long ans = 0;
	mp[0]++;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		pos[k].push_back(i);
		int cnt = pos[k].size();
		if (cnt % 3 == 1) h[i] = h[i - 1] ^ a[k];
		else if (cnt % 3 == 2) h[i] = h[i - 1] ^ b[k];
		else h[i] = h[i - 1] ^ a[k] ^ b[k];
		if (cnt > 3) {
			int x = pos[k][cnt - 4];
			while (cur < x - 1) {
				mp[h[cur]]--;
				cur++;
			}
		}
		ans += mp[h[i]];
		mp[h[i]]++;
	}
	cout << ans << '\n';
    return 0;
}