#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c, d; cin >> a >> b >> c >> d;
	cout << max({a * c, a * d, b * c, b * d}) << '\n';
    return 0;
}