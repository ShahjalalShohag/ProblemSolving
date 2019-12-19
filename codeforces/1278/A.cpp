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
        string a, b; cin>>a>>b;
        int n=a.size(), m=b.size();
        sort(a.begin(), a.end());
        int ok=0;
        for(int i=0; i+n-1<m; i++){
            string nw=b.substr(i, n);
            sort(nw.begin(), nw.end());
            if(nw==a) ok=1;
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
