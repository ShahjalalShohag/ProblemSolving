#include<bits/stdc++.h>
using namespace std;

vector<int> yo(vector<int> a) {
	int mx = -2e9;
	for (int i = 0; i < a.size(); i++) mx = max(mx, a[i]);
	for (int i = 0; i < a.size(); i++) a[i] = mx - a[i];
	return a;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		long long k; cin >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		a = yo(a);
		if ((k - 1) & 1) a = yo(a);
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << '\n';
	}
    return 0;
}