#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=3e5+9;

map<int,int>mp;
int a[N];
int32_t main()
{
    int n=in(),k=in();
    mp[0]++;
    ll ans=0;
    for(int i=1;i<=n;i++){
        a[i]=in();
        a[i]--;
        a[i]+=a[i-1];
        a[i]%=k;
        if(i-k>=0) mp[a[i-k]]--;
        ans+=mp[a[i]];
        mp[a[i]]++;
    }
    cout<<ans<<nl;
    return 0;
}
