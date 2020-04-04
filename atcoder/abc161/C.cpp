#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main()
{
    long long n, k; cin >> n >> k; cout << min(n % k, (k - n % k)) << '\n';
    return 0;
}
