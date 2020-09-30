#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
void yo(int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	yo(l, mid);
	yo(mid + 1, r);
	for (int i = l; i <= mid; i++) {
		v.push_back({i, i + (r - l + 1) / 2});
	}
}
int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n; cin >> n;
   int k = 0;
   while ((1 << k) <= n) ++k;
   k--;
   yo(1, 1 << k);
   yo(n - (1 << k) + 1, n);
   cout << v.size() << '\n';
   for (auto x: v) {
   	cout << x.first << ' ' << x.second << '\n';
   }
   return 0;
}