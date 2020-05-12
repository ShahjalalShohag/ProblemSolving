#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

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
long long power(long long x, int k) {
	long long ans = 1;
	while (k--) ans *= x;
	return ans;
}
vector<int> a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	linear_sieve();
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		while (k > 1) {
			int x = spf[k]; int cnt = 0;
			while (k % x == 0) k /= x, cnt++;
			a[x].push_back(cnt);
		}
	}
	long long ans = 1;
	for (auto x: prime) {
		sort(a[x].begin(), a[x].end());
		if (a[x].size() == n) ans *= power(x, a[x][1]);
		else if (a[x].size() == n - 1) ans *= power(x, a[x][0]);
	}
	cout << ans << '\n';
    return 0;
}