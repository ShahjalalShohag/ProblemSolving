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

int a[N], cnt[2];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=1; i<=2*n; i++) cin>>a[i];
        cnt[1]=cnt[2]=0;
        map<int, int> mp;
        mp[0]=2*n+1;
        for(int i=2*n; i>=n+1; i--){
            cnt[a[i]]++;
            cerr<<cnt[1]<<' '<<cnt[2];
            int d=cnt[1]-cnt[2];
            mp[d]=i;
        }
        int ans=mp[0]-1;
        cnt[1]=cnt[2]=0;
        for(int i=1; i<=n; i++){
            cnt[a[i]]++;
            cerr<<cnt[1]<<' '<<cnt[2];
            int d=cnt[2]-cnt[1];
            if(mp.find(d)!=mp.end()){
                int p=mp[d];
                int nw=p-i-1;
                ans=min(ans, nw);
            }
        }
        cout<<ans<<nl;
    }
    return 0;
}
