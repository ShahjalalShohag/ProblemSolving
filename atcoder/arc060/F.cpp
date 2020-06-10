#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

vector<int> build_lps(string p) {
    int sz = p.size();
    vector<int> lps;
    lps.assign(sz + 1, 0);
    int j = 0;
    lps[0] = 0;
    for(int i = 1; i < sz; i++) {
        while(j >= 0 && p[i] != p[j]) {
            if(j >= 1) j = lps[j - 1];
            else j = -1;
        }
        j++;
        lps[i] = j;
    }
    return lps;
}
inline int min_rep(int n, int lps) {
	return n % (n - lps) == 0 ? n - lps : n;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int n = s.size();
    auto lps = build_lps(s);
    int cur = min_rep(n, lps[n - 1]);
    if (cur == 1) return cout << n << '\n' << 1 << '\n', 0;
    if (cur == n) return cout << 1 << '\n' << 1 << '\n', 0;
    cout << 2 << '\n';
    int ans = 0;
    vector<int> ok(n, 0);
    for (int i = 0; i + 1 < n; i++) {
    	if (min_rep(i + 1, lps[i]) == i + 1) ok[i] ++;
    }
    reverse(s.begin(), s.end());
    lps = build_lps(s);
    for (int i = 0; i + 1 < n; i++) {
    	if (min_rep(i + 1, lps[i]) == i + 1) ok[n - i - 2] ++;
    }
    for (int i = 0; i + 1 < n; i++) ans += ok[i] == 2;
    cout << ans << '\n';
    return 0;
}
