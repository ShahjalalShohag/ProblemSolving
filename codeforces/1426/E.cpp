#include<bits/stdc++.h>
using namespace std;

int a[3], b[3], n;
int common(int a, int b) {
	return max(0, a + b - n);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 3; i++) cin >> a[i];
	swap(a[1], a[2]);
	for (int i = 0; i < 3; i++) cin >> b[i];
	swap(b[1], b[2]);
	int mx = min(a[0], b[2]) + min(a[1], b[0]) + min(a[2], b[1]);
	int mn = common(a[0], b[2]) + common(a[1], b[0]) + common(a[2], b[1]);
	cout << mn << ' ' << mx << '\n';
    return 0;
}