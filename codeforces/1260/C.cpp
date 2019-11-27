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
        int a=in(), b=in(), k=in();
        if(a<b) swap(a,b);
        int st=__gcd(a,b);
        int p=1;
        a-=st;
        p+=a/b;
        if(a%b==0) p--;
        //deb(p);
        if(p<k) puts("OBEY");
        else puts("REBEL");
    }
    return 0;
}
