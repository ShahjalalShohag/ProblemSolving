#include<bits/stdc++.h>
using namespace std;

int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n; cin >> n;
   if (n % 2 == 0) {
      if (n != 2) {
         cout << "YES\n";
         return 0;
      }
   }
   cout << "NO\n";
   return 0;
}