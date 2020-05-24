#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

string s[55];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		int ok = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][j] == '1') {
					int f = 0;
					if (i + 1 == n || s[i + 1][j] == '1') f = 1;
					if (j + 1 == n || s[i][j + 1] == '1') f = 1;
					ok &= f;
				}
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}