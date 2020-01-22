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
        int n=in();
        vector<pii> a(n);
        for(auto &x: a) cin>>x.first>>x.second;
        sort(a.begin(), a.end());
        string s="";
        bool ok=1;
        int x=0, y=0;
        for(auto p: a){
            if(p.first>=x&&p.second>=y){
                s+=string(p.first-x, 'R');
                s+=string(p.second-y, 'U');
                x=p.first;
                y=p.second;
            }
            else{
                ok=0;
                break;
            }
        }
        if(ok) {puts("YES");puts(s.c_str());}
        else puts("NO");
    }
    return 0;
}
