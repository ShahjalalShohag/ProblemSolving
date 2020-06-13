#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, va, b, vb, t; cin >> a >> va >> b >> vb >> t;
	if (a < b) {
		if (b + vb * t <= a + va * t) cout << "YES\n";
		else cout << "NO\n";
	}	
	else {
		if (b - vb * t >= a - va * t) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}