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

int ans[505][505];
int32_t main()
{
    int n=in(), m=in();
    if(n==1&&m==1) return cout<<0<<nl, 0;
    if(n==1){
        for(int i=1; i<=m; i++) ans[1][i]=i+1;
    }
    else if(m==1){
        for(int i=1; i<=n; i++) ans[i][1]=i+1;
    }
    else{
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) ans[i][j]=i*(n+j);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cout<<ans[i][j]<<' ';
        cout<<nl;
    }
    return 0;
}
