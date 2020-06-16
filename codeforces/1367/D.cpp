#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N];
int32_t main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int m; cin >> m;
		string ans; ans.resize(m);
		vector<int> cur;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
			cur.push_back(i);
		}
		vector<int> cnt(26, 0);
		for (auto c: s) cnt[c - 'a']++;
		int k = 25;
		while (cur.size()) {
			vector<int> del;
			for (auto i: cur) {
				if (a[i] == 0) del.push_back(i);
			}
			assert(del.size() > 0);
			while (k >= 0 && cnt[k] < del.size()) k--;
			assert(k >= 0);
			for (auto i: del) {
				cur.erase(find(cur.begin(), cur.end(), i));
				ans[i] = char('a' + k);
			}
			for (auto i: cur) {
				for (auto j: del) a[i] -= abs(i - j);
			}
			k--;
		}
		cout << ans << '\n';
	}
    return 0;
}