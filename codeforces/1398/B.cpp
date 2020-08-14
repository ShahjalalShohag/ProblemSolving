#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		vector<int> v;
		for (int i = 0; s[i]; ) {
			int j = i + 1;
			while (s[j] && s[i] == s[j]) j++;
			if (s[i] == '1') v.push_back(j - i);
			i = j;
		}
		sort(v.rbegin(), v.rend());
		int ans = 0;
		for (int i = 0; i < v.size(); i += 2) ans += v[i];
		cout << ans << '\n';
	}
    return 0;
}