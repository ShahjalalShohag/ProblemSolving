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
    set<int> se({1, 2, 3});
    for(int i=1; i<=2; i++){
        int k=in();
        se.erase(k);
    }
    cout<<(*se.begin())<<nl;
    return 0;
}
