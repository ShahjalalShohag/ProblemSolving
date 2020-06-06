#include<bits/stdc++.h>
using namespace std;

const int N = 2030, mod = 998244353;

int dp1[N][N], n;
int yo1(int sum, int last) {
	if (sum > n) return 0;
	if (last > n) return sum >= 1 && sum <= n;
	int &ret = dp1[sum][last];
	if (ret != -1) return ret;
	ret = yo1(sum + last, last);
	ret += yo1(sum, last + 1);
	if (ret >= mod) ret -= mod;
	return ret;
}
map<int, int> dp2[N][N];
int yo2(int i, int sum, int last) {
	if (sum > n) return 0;
	if (last <= 0) return sum >= 1 && sum <= n;
	auto &ret = dp2[i][last];
	if (ret.find(sum) != ret.end()) return ret[sum];
	int ans = yo2(i + 1, sum + last * i, last);
	ans += yo2(i, sum, last - 1);
	if (ans >= mod) ans -= mod;
	ret[sum] = ans;
	return ans;
}
int valid(vector<int> &v, int k) {
	if (k == 0) return 1;
	if (accumulate(v.begin(), v.end(), 0) > n) return 0;
	if (k == 1) return 1;
	int sz = v.size();
	vector<int> prv;
	for (int i = 0; i < sz; i++) {
		for (int j = 1; j <= v[i]; j++) {
			prv.push_back(sz - i);
		}
	}
	reverse(prv.begin(), prv.end());
	return valid(prv, k - 1);
}
int backtrack(vector<int> &v, int k, int last = 1) {
	int ans = 0;
	if (valid(v, k)) ans++;
	else return 0;
	for (int i = last; i <= n; i++) {
		v.push_back(i);
		int cnt = backtrack(v, k, i);
		ans += cnt;
		v.pop_back();
		if (cnt == 0) break;
	}
	return ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k; cin >> n >> k;
	memset(dp1, -1, sizeof dp1);
	vector<int> v;
	if (k == 1) cout << yo1(0, 1) << '\n';
	else if (k == 2) cout << yo2(1, 0, n) << '\n';
	else cout << backtrack(v, k) - 1 << '\n';
    return 0;
}