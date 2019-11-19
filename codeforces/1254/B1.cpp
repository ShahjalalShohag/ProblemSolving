#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=3e5+9;

int A[N],a[N];
ll yo(vector<pair<ll,ll>> &v)
{
    //for(auto x:v) cout<<x.F<<' '<<x.S<<nl;
    //cout<<nl;
    ll sum=0;
    for(auto x:v) sum+=x.second;
    ll nw=0;
    for(auto x:v){
        nw+=x.second;
        if(nw*2>=sum){
            //debug(x.F);
            ll ans=0;
            for(auto y:v) ans+=y.second*abs(x.first-y.first);
            //debug(ans);
            return ans;
        }
    }
}
int32_t main()
{
    int n=in();
    ll sum=0;
    for(int i=1;i<=n;i++){
        A[i]=in();
        sum+=A[i];
    }
    vector<ll> v;
    for(ll k=2;k*k<=sum;k++){
        if(sum%k==0){
            while(sum%k==0) sum/=k;
            v.eb(k);
        }
    }
    if(sum>1) v.eb(sum);
    assert(v.size()<=20);
    ll res=1e18;
    for(auto x:v){
        //debug(x);
        ll ans=0;
        for(int i=1;i<=n;i++) a[i]=A[i]%x;
        ll nw=0;
        vector<pair<ll,ll>> p;
        for(int i=1;i<=n;i++){
            nw+=a[i];
            if(nw>=x){
                p.eb(i,a[i]-(nw-x));
                ans+=yo(p);
                p.clear();
                nw%=x;
                if(nw) p.eb(i,nw);
            }
            else if(a[i]) p.eb(i,a[i]);
        }
        res=min(res,ans);
    }
    if(res==1e18) res=-1;
    cout<<res<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

