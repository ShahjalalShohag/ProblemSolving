#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int need[4], sz[3], cnt[2];
vector<pair<int, int>> v;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> need[0] >> need[1];
    for(int i = 0; i < 3; i++) cin >> sz[i];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < sz[i]; j++){
            int k; cin >> k;
            v.push_back({k, i});
        }
    }
    sort(v.begin(), v.end());
    long long ans = 0, tot = 0;
    for(int i = v.size() - 1; i >= 0; i--){
        int ty = v[i].second;
        if(tot == need[0] + need[1]) continue;
        if(cnt[ty] == need[ty]) continue;
        if(ty < 2) cnt[ty]++;
        ans += v[i].first, tot++;
    }
    cout << ans << '\n';
    return 0;
}
