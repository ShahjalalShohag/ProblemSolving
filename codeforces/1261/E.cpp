#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 1e3 + 9;
const int mod = 1e9 + 7;

string ans[N];
int a[N];
int32_t main()
{
    int n=in();
    for(int i=0; i<n; i++){
        a[i]=in();
        ans[i]=string (n, '0');
    }
    ans[n]= string(n, '0');
    int st=0;
    for(int val=n; val>=1; val--){
        for(int i=0; i<n; i++) if(a[i]==val){
            for(int k=0; k<val; k++) ans[(st+k)%(n+1)][i]='1';
            ++st;
        }
    }
    printf("%d\n", n+1);
    for(int i=0; i<=n; i++) puts(ans[i].c_str());
    return 0;
}
