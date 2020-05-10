#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n; int tot = 0;
	vector<array<int, 3>> a, last; vector<int> ans;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		vector<char> v;
		for (auto x: s) {
			if (x == '(') tot++, v.push_back('(');
			else {
				tot--;
				if (v.size() && v.back() == '(') v.pop_back();
				else v.push_back(')');
			}
		}
		int op = 0, cl = 0;
		for (auto x: v) {
			op += x == '(';
			cl += x == ')';
		}
		if (op && !cl) ans.push_back(i), cur += op;
		else if (cl && !op) last.push_back({cl, 0, i});
		else if (op && cl) a.push_back({op - cl, op, i});
		else ans.push_back(i);
	}
	if (tot != 0) return cout << "No\n", 0;
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (auto x: a) {
		if (cur < x[1] - x[0]) return cout << "No\n", 0;
		cur += x[0];
		ans.push_back(x[2]);
	}
	for (auto x: last) {
		if (cur < x[0]) return cout << "No\n", 0;
		cur -= x[0];
		ans.push_back(x[2]);
	}
	cout << "Yes\n";
	//for (auto x: ans) cout << x << ' '; cout << '\n';
    return 0;
}