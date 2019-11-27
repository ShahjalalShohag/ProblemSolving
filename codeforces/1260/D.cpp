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

int n, p, m, t, a[N], b[N], l[N], r[N], d[N], nxt[N];
int yo(int x)
{
    for(int i=1; i<=p; i++) nxt[i]=0;
    for(int i=1; i<=m; i++) if(d[i]>x){
        nxt[l[i]]=max(nxt[l[i]],r[i]);
    }
    //for(int i=1; i<=p; i++) cout<<nxt[i]<<' ';
    //cout<<nl;
    int ans=0;
    for(int i=1; i<=p;){
        if(nxt[i]==0) ans++, i++;
        else{
            int last=nxt[i];
            int nw=i;
            while(nw<=last){
                last=max(last, nxt[nw]);
                nw++;
            }
            ans+= 3*(nw-i);
            i=nw;
        }
    }
    return ans+1;
}
int32_t main()
{
    n=in(), p=in(), m=in(), t=in();
    for(int i=1; i<=n; i++) a[i]=in();
    for(int i=1; i<=m; i++) l[i]=in(), r[i]=in(), d[i]=in();
    sort(a+1, a+n+1);
    int l=1, r=n, ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(yo(a[mid])<=t) ans=n-mid+1, r=mid-1;
        else l=mid+1;
    }
    //deb(yo(3));
    cout<<ans<<nl;
    return 0;
}
