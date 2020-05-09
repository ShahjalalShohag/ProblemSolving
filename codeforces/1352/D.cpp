#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N], tot[3];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int cnt = 0; int k = 1, last = 0; tot[0] = tot[1] = 0;
		for (int l = 1, r = n; l <= r; ) {
			int sum = 0;
			if (k) {
				while (l <= r && sum <= last) {
					sum += a[l]; l++;
				}
			}
			else {
				while (r >= l && sum <= last) {
					sum += a[r]; r--;
				}
			}
			cnt++;
			tot[k] += sum;
			last = sum; k ^= 1;
		}
		cout << cnt << ' ' << tot[1] << ' ' << tot[0] << '\n';
	}
    return 0;
}