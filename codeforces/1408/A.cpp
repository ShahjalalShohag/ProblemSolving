#include<bits/stdc++.h>
using namespace std;

int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t; cin >> t;
   while (t--) {
   	int n; cin >> n;
   	vector<int> a(n), b(n), c(n), ans(n);
   	for (auto &x: a) cin >> x;
   	for (auto &x: b) cin >> x;
   	for (auto &x: c) cin >> x;
   	ans[0] = a[0];
   	for (int i = 1; i < n; i++) {
   		if (a[i] != ans[i - 1] && (i == n - 1 ? a[i] != ans[0] : 1)) {
   			ans[i] = a[i];
   		}   		
   		else if (b[i] != ans[i - 1] && (i == n - 1 ? b[i] != ans[0] : 1)) {
   			ans[i] = b[i];
   		}
   		else ans[i] = c[i];
   	}
   	for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << '\n';
   }
   return 0;
}