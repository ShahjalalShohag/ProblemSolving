#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
const long long inf = 1e18;
long long mul(long long a, long long b) {
  if (a <= inf / b) return a * b;
  return inf;
}
string solve(vector<int> a) {
  if (a.size() <= 1) return "";
  int n = a.size(), l = -1, r = n - 1;
  for (int i = 0; i < n; i++) {
    if (a[i] != 1) {
      l = i; break;
    }
  }
  if (l == -1) {
    return string(n - 1, '+');
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != 1) {
      r = i;
      break;
    }
  }
  long long m = 1;
  for (int i = l; i <= r; i++) {
    m = mul(m, a[i]);
  }
  if (m >= inf) {
    return string(l, '+') + string(r - l, '*') + string(n - r - 1, '+');
  }
  vector<int> dp(n + 1, 0), pre(n + 1, 0);
  for (int i = l; i <= r; i++) {
    if (a[i] == 1) {
      dp[i] = 1 + (i ? dp[i - 1] : 0);
      pre[i] = i - 1;
      continue;
    }
    long long cur = 1;
    for (int j = i; j >= l; j--) {
      cur *= a[j];
      long long p = cur + (j ? dp[j - 1] : 0);
      if (p > dp[i]) {
        dp[i] = p;
        pre[i] = j - 1;
      }
    }
  }
  string ans = "";
  for (int i = r; i >= l; i = pre[i]) {
    ans += string(i - pre[i] - 1, '*');
    ans += '+';
  }
  ans.pop_back();
  reverse(ans.begin(), ans.end());
  ans = string(l, '+') + ans + string(n - r - 1, '+');
  return ans;
}
int a[N], n;
void print(string s) {
  s.resize(n - 1);
  for (int i = 1; i <= n; i++) {
    if (i > 1) cout << s[i - 2];
    cout << a[i];
  }
  cout << '\n';
  exit(0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  string s; cin >> s;
  if (n == 1) {
    print("*");
  }
  if (s.size() == 1) {
    print(string(n - 1, s[0]));
  }
  if (s.size() == 3) {
    s.erase(find(s.begin(), s.end(), '-'));
  }
  if (s == "+-" || s == "-+") {
    print(string(n - 1, '+'));
  }  
  if (s == "*-" || s == "-*") {
    string ans = "";
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) {
        if (i != 1) ans += '-';
        break;
      }
      if (i > 1) ans += '*';
    }
    while (ans.size() < n - 1) ans += '*';
    print(ans);
  }
  vector<int> cur;
  string ans = "";
  for (int i = 1; i <= n + 1; i++) {
    if (a[i] == 0) {
      if (!cur.empty()) {
        if (cur.size() < i - 1) ans += '+';
        ans += solve(cur);
      }
      if (i != 1) ans += "+";
      cur.clear();
    }
    else cur.push_back(a[i]);
  }
  print(ans);
  return 0;
}