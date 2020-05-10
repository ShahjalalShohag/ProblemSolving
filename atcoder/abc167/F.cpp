#include<bits/stdc++.h>
using namespace std;
 
const int N = 3e5 + 9;
 
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n; int tot = 0;
	vector<array<int, 3>> pos, neg;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		int mn = 0, cur = 0;
		for (auto x: s) {
			if (x == '(') cur++;
			else cur--;
			mn = min(mn, cur);
		}
		if (cur >= 0) pos.push_back({-mn, -cur, i});
		else neg.push_back({mn - cur, -cur, i});
		tot += cur;
	}
	if (tot != 0) return cout << "No\n", 0;
	sort(pos.begin(), pos.end());
	int cur = 0; vector<int> ans;
	for (auto x: pos) {
		if (x[0] > cur) return cout << "No\n", 0; 
		cur -= x[1];
		ans.push_back(x[2]);
	}
	sort(neg.begin(), neg.end());
	for (auto x: neg) {
		if (x[1] - x[0] > cur) return cout << "No\n", 0;
		cur -= x[1];
		ans.push_back(x[2]);
	}
	cout << "Yes\n";
    return 0;
}