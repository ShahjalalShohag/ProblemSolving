#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N], vis[N], id[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; long long k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	vis[1] = 1;
	id[1] = 0; int nw = 1; vector<int> v; v.push_back(1);
	while (1) {
		int p = a[nw];
		if (vis[p]) {
			int s = id[p];
			if (k <= s) cout << v[k] << '\n';
			else {
				k -= s;
				k %= ((int)v.size() - s);
				cout << v[s + k] << '\n';
			}
			return 0;
		}
		vis[p] = 1;
		id[p] = id[nw] + 1;
		nw = p;
		v.push_back(p);
	}
    return 0;
}