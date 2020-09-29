#include<bits/stdc++.h>
using namespace std;

int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
	int n; cin >> n;
	string s = "NO\nYES";
	cout << s.substr((n % 2 == 0 && n != 2) * 3, 3);
   return 0;
}