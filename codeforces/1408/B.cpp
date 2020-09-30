#include<bits/stdc++.h>
using namespace std;

int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t; cin >> t;
   while (t--) {
   	int n, k; cin >> n >> k;
   	vector<int> a(n);
   	set<int> se;
   	for (int i = 0; i < n; i++) {
   		cin >> a[i];
   		se.insert(a[i]);
   	}
   	if (k == 1 && se.size() > 1) cout << -1 << '\n';
   	else {
   		se.clear();
   		int ans = 1;
   		for (int i = 0; i < n; i++) {
   			se.insert(a[i]);
   			if (se.size() > k) {
   				ans++;
   				se.clear();
   				se.insert(0);
   				se.insert(a[i]);
   			}
   		}
   		cout << ans << '\n';
   	}
   }
   return 0;
}