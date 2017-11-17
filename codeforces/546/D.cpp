#include <bits/stdc++.h>
using namespace std;
const int sz = 5000010;
typedef long long ll;
ll sp[sz];
ll f[sz];
void sieve() {
    for (int i = 2; i < sz; ++i) {
        if (sp[i] == 0) {
            for (int j = 1; j * i < sz; j++) {
                sp[i * j] = i;
            }
        }
    }
    for (ll i = 2; i < sz; ++i) {
        f[i] = f[i / sp[i]] + 1;
    }
    for (ll i = 2; i < sz; ++i) {
        f[i] += f[i - 1];
    }
}
int main() {
    int n, a, b;
    scanf("%d", &n);
    sieve();
    while (n--) {
        scanf("%d %d", &a, &b);
        printf("%I64d\n", f[a] - f[b]);
    }
    return 0;
}