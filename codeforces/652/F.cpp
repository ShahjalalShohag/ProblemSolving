#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; long long t; cin >> n >> m >> t;
    long long mod = 1LL * n * m, move = 0;
    vector<int> finish;
    vector<pair<int, int>> start;
    for (int i = 0; i < n; i++) {
        int s; char d; cin >> s >> d;
        int speed = d == 'L' ? -1 : 1;
        (move += speed * t) %= mod;
        if (move < 0) move += mod;
        int fin = ((s + speed * t - 1) % m + m) % m + 1;
        start.push_back({s, i});
        finish.push_back(fin);
    }
    sort(start.begin(), start.end());
    sort(finish.begin(), finish.end());
    long long move2 = 0;
    for (int i = 0; i < n; i++) {
        (move2 += finish[i] - start[i].first) %= mod;
        if (move2 < 0) move2 += mod;
    }
    int rot = ((move - move2) / m % n + n) % n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[start[i].second] = finish[(i + rot) % n];
    }
    for (auto x: ans) cout << x << ' '; cout << '\n';
    return 0;
}