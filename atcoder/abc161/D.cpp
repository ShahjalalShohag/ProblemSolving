#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

vector<int> v;
long long dp[20][10][2][2];
long long yo(int i, int last, int f, int st)
{
    if(i == -1) return 1;
    long long &ret = dp[i][last][f][st];
    if(ret != -1) return ret;
    int m = f ? v[i] : 9;
    long long ans = 0;
    for(int k = 0; k <= m; k++){
        if(!st|| abs(k - last) <= 1)
            ans += yo(i - 1, k, k == m? f : 0, st |  (k > 0));
    }
    ret = ans;
    return ans;
}
long long solve(long long n)
{
    if(n == 0) return 0;
    memset(dp, -1, sizeof dp);
    v.clear();
    while(n){
        v.push_back(n % 10); n /= 10;
    }
    return yo((int)v.size() - 1, 0, 1, 0) - 1;
}

int32_t main()
{
    int k; cin >> k;
    long long l = 1, r = 4e9, ans;
    while(l <= r){
        long long mid = (l + r) / 2;
        if(solve(mid) < k)  l = mid + 1;
        else ans = mid, r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
