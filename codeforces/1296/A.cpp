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
    int t = in();
    while(t--){
        int n = in();
        int sum = 0, odd = 0;
        for(int i =1 ; i <= n; i++){
            int k = in();
            k %= 2;
            sum += k;
            odd += k;
        }
        sum %= 2;
        if(sum == 1 || !(odd == 0 || odd == n)) puts("YES");
        else puts("NO");
    }
    return 0;
}
