#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main()
{
    long long n, ans = 0;
    cin >> n;
    ans += n / 500 * 1000;
    n %= 500;
    while(n >= 5) ans += 5, n-= 5;
    cout << ans << '\n';
    return 0;
}
