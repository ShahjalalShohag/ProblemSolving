#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main()
{
    long long n; cin >> n;
    long long ans = 0;
    for(long long i = 2; i * i <= n; i++) if(n % i == 0){
        long long p = n;
        while(p % i == 0)  p /= i;
        if(p == 1 || (p - 1) % i == 0) ans++;
        if(i != n / i){
            p = n;
            while(p % (n / i) == 0)  p /= n / i;
            if(p == 1 || (p - 1) % (n / i) == 0) ans++;
        }
    }
    ans++; n--;
    for(long long i = 2; i * i <= n; i++) if(n % i == 0){
        ans += 1 + (i != n / i);
    }
    ans += n > 1;
    cout << ans << '\n';
    return 0;
}
