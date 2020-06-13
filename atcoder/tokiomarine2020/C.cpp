#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	while (k--) {
		vector<int> sum(n + 1, 0);
		for (int i = 0; i < n; i++) {
			sum[max(0, i - a[i])]++;
			sum[min(n, i + a[i] + 1)]--;
		}
		for (int i = 1; i < n; i++) {
			sum[i] += sum[i - 1];
		}
		int all = 1;
		for (int i = 0; i < n; i++) {
			a[i] = min(n, sum[i]);
			all &= a[i] == n;
		}
		if (all) break;
	}
	for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << '\n';
    return 0;
}