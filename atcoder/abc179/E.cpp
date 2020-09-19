#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
 
int f[N][40];
long long s[N][40];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long k; cin >> k;
	int x, n; cin >> x >> n;
	for (int i = 0; i < n; i++) f[i][0] = 1LL * i * i % n;
	for (int i = 0; i < n; i++) s[i][0] = i;
	for (int k = 1; k < 40; k++) {
		for (int i = 0; i < n; i++) {
			f[i][k] = f[f[i][k - 1]][k - 1];
			s[i][k] = s[i][k - 1] + s[f[i][k - 1]][k - 1];
		}
	}
	int cur = x;
	long long sum = 0;
	for (int i = 0; i < 40; i++) {
		if (k >> i & 1) {
			sum += s[cur][i];
			cur = f[cur][i];
		}
	}
	cout << sum;
    return 0;
}