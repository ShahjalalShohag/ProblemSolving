#include<bits/stdc++.h>
using namespace std;

const int N = 4e4 + 9;
int spf[N];///smallest prime factor
vector<int> prime;
void linear_sieve()
{
    for(int i=2;i<N;i++){
        if(spf[i]==0) spf[i]=i,prime.push_back(i);
        int sz=prime.size();
        for(int j=0;j<sz&&i*prime[j]<N&&prime[j]<=spf[i];j++) spf[i*prime[j]]=prime[j];
    }
}
long long M = 1e18;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	linear_sieve();
	int n = 1e9;
	vector<long long> v;
	for (auto x: prime) {
		long long nw = 1, pw = 0;
		while (nw < n) nw *= x, pw++;
		pw = (pw + 1) / 3;
		if (x <= 50) pw++;
		nw = 1; while (pw --) nw *= x;
		if (x <= 617) {
			v.push_back(nw);
		}
	}
	while (1) {
		sort(v.begin(), v.end());
		int i = v.size() - 1;
		while (i && v[0] >= M / v[i]) i--;
		if (i <= 0) break;
		auto x = v[0];
		auto y = v[i];
		v.erase(v.begin() + i);
		v.erase(v.begin());
		v.push_back(x * y);
	}
	//cout << v.size() << '\n'; return 0;
	int t; cin >> t;
	while (t--) {
		long long x = 1;
		for (auto y: v) {
			cout << "? " << y << '\n';
			cout.flush();
			long long k; cin >> k;
			x = x / __gcd(x, k) * k;
		}
		long long ans = 0;
		for (long long i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				ans++;
				if (i != x / i) ans++;
			}
		}
		cout << "! " << max(ans + 7, 2 * ans) << '\n';
		cout.flush();
	}
    return 0;
}