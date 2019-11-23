#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=3e5+9;
const int mod=1e9+7;

char ask(vector<int> v)
{
    cout<<"?";
    for(auto x:v) cout<<' '<<x;
    cout<<nl;
    cout.flush();
    string s;
    cin>>s;
    return s[0];
}
char res[300];
int32_t main()
{
    int n=in();
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    char first = ask(v);
    int l=2,r=n+1,ans;
    while(l<=r){
        int mid = (l+r)>>1;
        vector<int> v;
        for(int i=mid; i<mid+n; i++) v.eb(i);
        if(first!=ask(v)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    v.clear();
    for(int i=ans; i<=ans+n-2; i++) v.eb(i);
    for(int i=1; i<ans; i++){
        v.eb(i);
        res[i]=ask(v);
        v.pop_back();
    }
    for(int i=ans+n-1; i<=2*n; i++){
        v.eb(i);
        res[i]=ask(v);
        v.pop_back();
    }
    v.clear();
    for(int i=1; i<=2*n; i++){
        if(i>=ans&&i<=ans+n-2);
        else v.eb(i);
    }
    for(auto x:v){
        if(res[x]=='R'){
            v.erase(find(v.begin(), v.end(),x));
            break;
        }
    }
    for(auto x:v){
        if(res[x]=='B'){
            v.erase(find(v.begin(), v.end(),x));
            break;
        }
    }

    for(int i=ans;i<=ans+n-2;i++){
        v.eb(i);
        res[i]=ask(v);
        v.pop_back();
    }
    cout<<"! ";
    for(int i=1;i<=2*n;i++) cout<<res[i];
    cout<<nl;
    cout.flush();
    return 0;
}
