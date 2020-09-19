#include<bits/stdc++.h>
using namespace std;

int a[200];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int p, q; cin >> p >> q;
		a[i] = p == q;
	}
	for (int i = 0; i + 2 < n; i++) {
		if (a[i] && a[i + 1] && a[i + 2]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
    return 0;
}