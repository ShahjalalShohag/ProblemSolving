#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;


int32_t main()
{
    int n=in();
    vector<int> a(n), b(n), v;
    for(auto &x: a) cin>>x;
    for(auto &x: b) cin>>x;
    for(int i=1; i<=n; i++) v.eb(i);
    int ca, cb, cnt=0;
    do{
        cnt++;
        if(v==a) ca=cnt;
        if(v==b) cb=cnt;
    }while(next_permutation(v.begin(), v.end()));
    cout<<abs(ca-cb)<<nl;
    return 0;
}
