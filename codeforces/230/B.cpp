#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

bitset<N> f;
int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   map<long long, int> mp;
   f.set();
   for (int i = 2; i < N; i++) {
   	if (f[i] == 1) {
   		mp[1LL * i * i] = 1;
   		for (int j = i + i; j < N; j += i) {
   			f[j] = 0;
   		}
   	}
   }
   int t; cin >> t;
   while (t--) {
   	long long n; cin >> n;
   	if (mp[n]) cout << "YES\n";
   	else cout << "NO\n";
   }
   return 0;
}