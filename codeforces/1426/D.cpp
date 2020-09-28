#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int ans = 0;
	long long sum = 0;
	map<long long, int> mp;
	mp[0] = 1;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		sum += k;
		if (mp[sum]) {
			mp.clear();
			mp[0] = 1;
			ans ++; 
			sum = k;
		}
		mp[sum] = 1;
	}
	cout << ans << '\n';
    return 0;
}