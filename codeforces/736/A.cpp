#include<bits/stdc++.h>
using namespace std;

long long f[300];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n; cin >> n;
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; ; i++) {
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] > n) return cout << i - 2 << '\n', 0;
	}
    return 0;
}