#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	cout << "?" << ' ' << 1 << ' ' << n << '\n';
	cout.flush();
	map<string, int> mp;
	for (int i = 0; i < n * (n + 1) / 2; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		mp[s]++;
	}
	if (n == 1) {
		cout << "! " << mp.begin() -> first << '\n'; cout.flush();
		return 0;
	}
	cout << "?" << ' ' << 2 << ' ' << n << '\n';
	cout.flush();
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		mp[s]--;
	}
	vector<string> v;
	for (auto x: mp) {
		if (x.second) v.push_back(x.first);
	}
	assert(v.size() == n);
	sort(v.begin(), v.end(), [](string &a, string &b) {return a.size() < b.size();});
	string ans = v[0];
	for (int i = 1; i < n; i++) {
		string s = v[i];
		for (auto x: ans) s.erase(find(s.begin(), s.end(), x));
		assert(s.size() == 1);
		ans += s;
	}
	cout << "! " << ans << '\n';
	cout.flush();
    return 0;
}
