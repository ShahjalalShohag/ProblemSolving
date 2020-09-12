#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int a[N];
long long diff[N], ans;

void yo(int i, long long x) {
	if (i == 1) {
		ans -= diff[i];
		diff[i] += x;
		ans += diff[i];
	}
	else {
		ans -= max(0LL, diff[i]);
		diff[i] += x;
		ans += max(0LL, diff[i]);
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		yo(i, a[i] - a[i - 1]);
	}
	cout << (ans < 0 ? ans / 2 : (ans + 1) / 2)<< '\n';
	int q; cin >> q;
	while (q--) {
		int l, r, x; cin >> l >> r >> x;
		yo(l, x);
		if (r < n) {
			yo(r + 1, -x);
		}
		cout << (ans < 0 ? ans / 2 : (ans + 1) / 2) << '\n';
	}
    return 0;
}