#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

int a[N], ans[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(ans, -1, sizeof ans);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != a[i - 1]) {
			for (int k = a[i - 1], id = i; k < a[i]; id--) {
				if (ans[id] == -1) ans[id] = k++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == -1) ans[i] = N;
		cout << ans[i] << ' ';
	}
	cout << '\n';
    return 0;
}