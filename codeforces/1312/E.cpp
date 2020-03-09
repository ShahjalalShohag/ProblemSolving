#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 501;
const int mod = 1e9 + 7;

#define int short
int dp[N], a[N]; bool ok[N][N];
int32_t main()
{
    int n = in();
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        stack<int> st;
        for(int j = i; j <= n; j++){
            st.push(a[j]);
            while(1){
                if(st.empty()) break;
                int u = st.top();
                st.pop();
                if(st.empty()){st.push(u); break;}
                if(st.top() == u) st.pop(), st.push(u + 1);
                else {st.push(u); break;}
            }
            if(st.size() == 1) ok[i][j] = 1;
        }
    }
    for(int i = n; i >= 1; i--){
        dp[i] = 1000;
        for(int j = i; j <= n; j++) if(ok[i][j]){
            int oth = dp[j + 1] + 1;
            dp[i] = min(dp[i], oth);
        }
    }
    cout << dp[1] << nl;
    return 0;
}

