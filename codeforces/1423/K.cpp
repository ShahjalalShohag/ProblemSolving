#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int spf[N], ans[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      ans[i]++;
      ans[min(1LL * i * i, N - 1LL)]--;
    }
  }
  for (int i = 2; i < N; i++) {
    ans[i] += ans[i - 1];
  }
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << ans[n] + 1 << '\n';
  }
  return 0;
}