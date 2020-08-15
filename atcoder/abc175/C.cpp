#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n, k, d; cin >> n >> k >> d;
	n = abs(n);
	long long p = n / d;
	if (k <= p) cout << n - k * d << '\n';
	else if (k % 2 == p % 2) cout << n % d << '\n';
	else cout << d - n % d << '\n';
    return 0;
}