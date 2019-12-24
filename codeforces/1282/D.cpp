#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

int query(string s)
{
    cout<<s<<nl;
    cout.flush();
    int k;
    cin>>k;
    if(k==0) exit(0);
    return k;
}
int32_t main()
{
    int a=query("a");
    int n;
    if(a==300) n=a;
    else n=a+1;
    string s=string (n, 'a');
    int k=query(s);
    if(a<300&&k==n){
        int p=query(string(n-1, 'b'));
        return 0;
    }
    int b=k;
    a=n-k;
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    shuffle(id.begin(), id.end(), rnd);
    int last=k;
    string ans(n, 'a');
    for(int x=0; x+1<n; x++){
        if(b==0){
            for(int i=x; i<n; i++) ans[id[i]]='a';
            int k=query(ans);
            return 0;
        }
        if(a==0){
            for(int i=x; i<n; i++) ans[id[i]]='b';
            int k=query(ans);
            return 0;
        }
        int i=id[x];
        s[i]='b';
        int k=query(s);
        if(k<last) ans[i]='b', b--;
        else ans[i]='a', a--;
        s[i]='a';
    }
    if(a) ans[id[n-1]]='a';
    if(b) ans[id[n-1]]='b';
    int p=query(ans);
    return 0;
}

