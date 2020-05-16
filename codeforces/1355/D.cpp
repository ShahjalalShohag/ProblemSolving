#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, s; cin >> n >> s;
	if (s < 2 * n) return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i = 1; i < n; i++) cout << 2 << ' ';
	cout << s - 2 * (n - 1) << '\n';
	cout << 1 << '\n';
    return 0;
}