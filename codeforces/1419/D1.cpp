#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	cout << (n - 1) / 2 << '\n';
	for (int i = (n - 1) / 2, j = 0; i < n; i++, j++) {
		cout << a[i] << ' ';
		if (j < (n - 1) / 2) cout << a[j] << ' ';
	}
    return 0;
}