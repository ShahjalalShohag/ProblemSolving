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
    string s; cin>>s;
    int ans=0;
    for(int i=0; i+2<n; i++) if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') ans++;
    cout<<ans<<nl;
    return 0;
}
