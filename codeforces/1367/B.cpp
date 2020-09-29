#include<bits/stdc++.h>
using namespace std;

int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t; cin >> t;
   while (t--) {
   	int n; cin >> n;
   	vector<int> cnt(2, 0);
   	int tot = 0;
   	for (int i = 0; i < n; i++) {
   		int k; cin >> k;
   		if (k % 2 != i % 2) {
   			tot++;
   		}
   		cnt[k % 2]++;
   	}
   	if (cnt[1] == n / 2) {
   		cout << (tot + 1) / 2 << '\n';
   	}
   	else {
   		cout << -1 << '\n';
   	}
   }
   return 0;
}