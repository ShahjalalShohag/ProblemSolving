#include<bits/stdc++.h>
using namespace std;

const int N = 55;

int r[N], c[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int k; cin >> k;
				if (k) r[i]++, c[j]++;
			}
		}
		int row = 0, col = 0;
		for (int i = 0; i < n; i++) row += !r[i];
		for (int i = 0; i < m; i++) col += !c[i];
		if (min(row, col) & 1) cout << "Ashish\n";
		else cout << "Vivek\n";
	}
    return 0;
}