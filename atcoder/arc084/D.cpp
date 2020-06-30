#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
bool vis[N][60];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int sum = 0;
	int k = n;
	while (k) {
		sum += k % 10;
		k /= 10;
	}
	queue<pair<int, int>> q;
	q.push({1, 1});
	vis[1][1] = 1;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int k = x.first, d = x.second;
		for (int i = 0; i <= 9; i++) {
			int nk = (k * 10 + i) % n, nd = d + i;
			if (nd <= sum && !vis[nk][nd]) {
				vis[nk][nd] = 1;
				q.push({nk, nd});
			}
		}
	}
	for (int i = 0; i <= sum; i++) {
		if (vis[0][i]) {
			cout << i << '\n';
			return 0;
		}
	}
	assert(0);
    return 0;
}