#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

long long ans;
int a[N], n; long long p[N];
int add , rem, mov;
inline long long yo(int x) {
	if (x < 0) return 4e18;
	int id = upper_bound(a + 1, a + n + 1, x) - a;
	long long up = p[n] - p[id - 1] - 1LL * x * (n - id + 1);
	long long dn = 1LL * x * (id - 1) - p[id - 1];
	long long z = up * rem + dn * add;
	//ans = min(ans, z);
	long long k = min(up, dn);
	long long nw = k * mov;
	up -= k;
	dn -= k;
	nw += up * rem + dn * add;
	//ans = min(ans, nw);
	return min(nw, z);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> add >> rem >> mov;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
	long long l = 0, r = a[n] + a[n] + 1;
	while (l < r) {
		long long mid = (l + r) / 2;
		if (yo(mid + 1) < yo(mid)) l = mid + 1;
		else r = mid;
	}
	cout << yo(l) << '\n';
    return 0;
}