#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n; cin >> k >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int m = 0;
    for(int i = 0; i < n - 1; i++) m = max(m, abs(a[i] - a[i + 1]));
    m = max(m, a[0] + k - a[n - 1]);
    cout << k - m << '\n';
    return 0;
}
