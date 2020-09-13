#include<bits/stdc++.h>
using namespace std;

int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l, r; cin >> l >> r;
	int ans = 0;
	for (int i = l; i <= r; i++) {
		int k = i;
		while (k) {
			ans += a[k % 10];
			k /= 10;
		}
	}
	cout << ans << '\n';
    return 0;
}