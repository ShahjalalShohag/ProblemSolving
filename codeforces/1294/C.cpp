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
    int t=in();
    while(t--){
        ll n; cin>>n;
        vector<ll> v;
        for(ll i=2; i*i<=n; i++) if(n%i==0){
            v.eb(i);
            if(i!=n/i) v.eb(n/i);
        }
        sort(v.begin(), v.end());
        vector<ll> ans;
        for(auto x: v) for(auto y: v) if(x*y<n&&n%(x*y)==0&&x!=y&&x!=n/(x*y)&&y!=n/(x*y)){
            ans.eb(x);
            ans.eb(y);
            ans.eb(n/(x*y));
            goto hell;
        }
        hell:
        if(!ans.empty()){
            puts("YES");
            for(auto x: ans) cout<<x<<' ';
            cout<<nl;
        }
        else puts("NO");
    }
    return 0;
}
