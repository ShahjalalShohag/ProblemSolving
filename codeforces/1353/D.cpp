#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

struct cmp {
    bool operator()(const pair<int, int> a, const pair<int, int> b) {
        int lena = a.second - a.first + 1, lenb = b.second - b.first + 1;
        if (lena == lenb) return a.first < b.first;
        else return lena > lenb;
    }
};
int ans[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<pair<int, int>, cmp> se;
		se.insert({1, n}); int k = 1;
		while (se.size()) {
			auto x = *se.begin();
			se.erase(se.begin());
			int l = x.first, r = x.second;
			int mid = l + r >> 1;
			ans[mid] = k++;
			if (l < mid) se.insert({l, mid - 1});
			if (mid < r) se.insert({mid + 1, r});
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
	}
    return 0;
}