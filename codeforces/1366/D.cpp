#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9, M = 5e5 + 9;

int spf[N];///smallest prime factor
vector<int> prime;
void linear_sieve() {
    for(int i=2;i<N;i++){
        if(spf[i]==0) spf[i]=i,prime.push_back(i);
        int sz=prime.size();
        for(int j=0;j<sz&&i*prime[j]<N&&prime[j]<=spf[i];j++) spf[i*prime[j]]=prime[j];
    }
}
bool vis[N];
pair<int, int> mp[N], ans[M];
pair<int, int> yo(int n, vector<int> &d) {
	if (vis[n]) return mp[n];
	vis[n] = 1;
	for (int i = 0; i < d.size(); i++) {
		for (int j = i + 1; j < d.size(); j++) {
			if (__gcd(d[i] + d[j], n) == 1) {
				mp[n] = {d[i], d[j]};
				return mp[n];
			}
			if (__gcd(d[i] + n / d[i], n) == 1) {
				mp[n] = {d[i], n / d[i]};
				return mp[n];
			}
		}
	}
	return mp[n] = {-1, -1};
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	linear_sieve();
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		vector<int> d;
		int k = n; int f = 0;
		while (k > 1) {
			int z = spf[k];
			int nw = 1;
			while (k % z == 0) {
				k /= z;
				nw *= z;
				d.push_back(nw);
			}
			f++;
		}
		if (f == 1) ans[i] = {-1, -1};
		else ans[i] = yo(n, d);
	}
	for (int i = 0; i < t; i++) cout << ans[i].first << ' '; cout << '\n';
	for (int i = 0; i < t; i++) cout << ans[i].second << ' '; cout << '\n';
    return 0;
}