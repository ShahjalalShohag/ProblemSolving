#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;


int32_t main()
{
    int n = in();
    int ok = 1;
    while(n--){
        int k = in();
        if(k % 2 == 0){
            if(k % 3== 0 || k % 5 == 0);
            else ok = 0;
        }
    }
    if(ok) puts("APPROVED");
    else puts("DENIED");
    return 0;
}
