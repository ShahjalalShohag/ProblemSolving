#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 5e5 + 9;
const int mod = 1e9 + 7;

int cnt[N];
int32_t main()
{
    int q=in(), x=in();
    int ans=0;
    while(q--){
        int k=in();
        cnt[k%x]++;
        while(cnt[ans%x]) cnt[ans%x]--, ans++;
        printf("%d\n", ans);
    }
    return 0;
}
