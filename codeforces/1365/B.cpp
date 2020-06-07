#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N], b[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int z = 0, o = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i], z += !b[i], o += b[i];
		if (z && o) cout << "Yes\n";
		else {
			int ok = 1;
			for (int i = 1; i < n; i++) ok &= a[i] <= a[i + 1];
			if (ok) cout << "Yes\n";
			else cout << "No\n";
		}
	}
    return 0;
}