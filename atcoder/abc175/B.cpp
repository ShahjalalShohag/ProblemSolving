#include<bits/stdc++.h>
using namespace std;

int a[200];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				set<int> se;
				se.insert(a[i]);
				se.insert(a[j]);
				se.insert(a[k]);
				vector<int> v(se.begin(), se.end());
				if (v.size() == 3 && v[0] + v[1] > v[2]) ans++;
			}
		}
	}
	cout << ans << '\n';
    return 0;
}