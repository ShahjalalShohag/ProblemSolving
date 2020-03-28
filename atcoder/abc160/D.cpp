#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int ans[N];
int32_t main()
{
    int n, x, y; cin >> n >> x >> y;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(i <= x && j <= x || i>= y && j >= y) ans[j - i]++;
            else{
                int d = 0, u = i, v = j;
                if(u <= x) d += x - u, u = x;
                if(v >= y) d += v - y, v = y;
                d += min(v - u, u - x + y - v + 1);
                ans[d]++;
            }
        }
    }
    for(int i = 1; i < n; i++) cout << ans[i] << '\n';
    return 0;
}
