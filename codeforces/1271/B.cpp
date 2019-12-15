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

void yo(vector<int> a)
{
    int n=a.size();
    vector<int> ans;
    for(int i=0; i+1<n; i++){
        if(a[i]!=0){
            ans.eb(i+1);
            a[i+1]^=1;
        }
    }
    if(a[n-1]==1) return;
    cout<<ans.size()<<nl;
    for(auto x: ans) cout<<x<<' ';
    cout<<nl;
    exit(0);
}
int32_t main()
{
    int n=in();
    string s;
    cin>>s;
    vector<int> a;
    for(auto x: s){
        if(x=='W') a.eb(0);
        else a.eb(1);
    }
    yo(a);
    for(auto &x: a) x^=1;
    yo(a);
    cout<<-1<<nl;
    return 0;
}
