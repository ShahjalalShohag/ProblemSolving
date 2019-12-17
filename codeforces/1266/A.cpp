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
        string s;
        cin>>s;
        int n=s.size();
        vector<int> v;
        int sum=0;
        for(auto x: s) v.eb(x-'0'), sum+=x-'0';
        int ok=0;
        if(find(v.begin(), v.end(), 0)!=v.end()&&sum%3==0){
            v.erase(find(v.begin(), v.end(), 0));
            for(auto x: v) if(x%2==0) ok=1;
        }
        if(ok) puts("red");
        else puts("cyan");
    }
    return 0;
}
