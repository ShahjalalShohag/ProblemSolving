#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	if (is_prime(n)) cout << 1 << '\n';
	else if (n % 2 == 1 && is_prime(n - 2)) cout << 2 << '\n';
	else cout << 2 + n % 2 << '\n';
    return 0;
}