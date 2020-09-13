#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int cnt[N];

void yo(vector<int> ans, vector<int> a) {
	int n = ans.size();
	for (int i = 0; i < n; i++) {
		if (a[i] == ans[i] || ans[i] == 0) return;
	}
	cout << "Yes\n";
	for (auto i: ans) cout << i << ' '; cout << '\n';
	exit(0);
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	yo(b, a);

	for (auto i: b) cnt[i]++;
	int mx = 0;
	for (int i = 1; i <= n; i++) mx = max(mx, cnt[i]);
	auto c = b;
	rotate(b.begin(), b.begin() + mx, b.end());
	yo(b, a);
	b = c;

	for (int i = 0; i < 50; i++) {
		set<pair<int, int>> se;
		vector<int> prior(n);
		if (i == 0) {
			for (int k = 0; k < n; k++) prior[k] = k;
		}		
		else if (i == 1) {
			for (int k = 0; k < n; k++) prior[k] = -k;
		}
		else {
			for (int k = 0; k < n; k++) prior[k] = rnd() % n + 1;
		}

		for (auto i: b) se.insert({prior[i], i});
		memset(cnt, 0, sizeof cnt);
		for (auto i: b) cnt[i]++;
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			if (se.empty()) break;
			auto it = se.begin();
			if ((*it).second == a[i]) {
				if (se.size() == 1) break;
				++it;
			}
			int k = (*it).second;
			ans[i] = k;
			cnt[k]--;
			if (cnt[k] == 0) se.erase({prior[k], k});
		}
		yo(ans, a);
	}

	memset(cnt, 0, sizeof cnt);
	for (auto i: a) cnt[i]++;
	mx = 0;
	for (int i = 1; i <= n; i++) mx = max(mx, cnt[i]);
	rotate(b.begin(), b.begin() + mx, b.end());
	yo(b, a);

	cout << "No\n";
    return 0;
}