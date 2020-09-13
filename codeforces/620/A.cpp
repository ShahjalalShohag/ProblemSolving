#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d; cin >> a >> b >> c >> d;
	cout << max(abs(a - c), abs(b - d)) << '\n';
    return 0;
}