#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

vector<int> id[201];
int cnt[201][N];
int query(int l, int r) {
	if(l > r) return 0;
	int ans = 0;
	for (int i = 1; i <= 200; i++) ans = max(ans, cnt[i][r] - cnt[i][l - 1]);
	return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
    	int n; cin >> n;
    	for (int i = 1; i <= n; i++) {
    		int k; cin >> k;
    		id[k].push_back(i);
    		cnt[k][i] ++;
    		for (int k = 1; k <= 200; k++) cnt[k][i] += cnt[k][i - 1];
    	}
    	int ans = query(1, n);
    	for (int k = 1; k <= 200; k++) {
    		int sz = id[k].size();
    		for (int i = 0, j = sz - 1; i < j; i++, j--) {
    			int l = id[k][i] + 1, r = id[k][j] - 1;
    			ans = max(ans, query(l, r) + i * 2 + 2);
    		}
    	}
    	cout << ans << '\n';
    	for (int i = 1; i <= 200; i++) {
    		for(int j = 1; j <= n; j++) cnt[i][j] = 0;
    		id[i].clear();
    	}
    }
    return 0;
}