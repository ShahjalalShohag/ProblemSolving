#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N];
int32_t main()
{
    int n, m; cin >> n >> m;
    int sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    sort(a + 1, a + n + 1);
    for(int i = n; i >= n - m + 1; i--){
        if(a[i] * 4 * m < sum) return cout << "No\n", 0;
    }
    cout << "Yes\n";
    return 0;
}
