#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 1e6 + 9;
const int mod = 1e9 + 7;


string s;
int n,dp[N][2];
int yo(int i,int k)
{
    if(i==n) return k;
    int &ret=dp[i][k];
    if(ret!=-1) return ret;
    ret=(s[i]-'0')+k+yo(i+1,0);///+10^i
    ret=min(ret,10-k-(s[i]-'0')+yo(i+1,1));///-10^i
    return ret;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
    reverse(s.begin(), s.end());
    n = s.size();
    memset(dp, -1, sizeof dp);
    cout<<yo(0,0)<<nl;
    return 0;
}
