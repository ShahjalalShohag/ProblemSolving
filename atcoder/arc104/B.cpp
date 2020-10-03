#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> cnt(2, 0);
        for (int j = i; j < n; j++) {
            if (s[j] == 'A') cnt[0]++;
            else if (s[j] == 'T') cnt[0]--;
            else if (s[j] == 'C') cnt[1]++;
            else cnt[1]--;
            if (cnt[0] == 0 && cnt[1] == 0) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}