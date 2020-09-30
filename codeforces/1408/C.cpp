#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

#define double long double
int a[N];
int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t; cin >> t;
   while (t--) {
   	int n, x; cin >> n >> x;
   	for (int i = 1; i <= n; i++) cin >> a[i];
   	a[n + 1] = x;
   	double l = 0, r = x;
   	int it = 200;
   	while (it--) {
   		double mid = (l + r) / 2, t = mid;
   		double nw1 = x;
   		for (int i = 1; i <= n + 1; i++) {
   			double cur = 1.0L * (a[i] - a[i - 1]) / i;
   			if (cur >= t) {
   				nw1 = a[i - 1] + 1.0L * i * t;
   				break;
   			}
   			else {
   				t -= cur;
   			}
   		}   		
   		double nw2 = 0;
   		t = mid;
   		for (int i = n; i >= 0; i--) {
   			double cur = 1.0L * (a[i + 1] - a[i]) / (n - i + 1);
   			if (cur >= t) {
   				nw2 = a[i + 1] - 1.0L * (n - i + 1) * t;
   				break;
   			}
   			else {
   				t -= cur;
   			}
   		}
   		if (nw1 >= nw2) {
   			r = mid;
   		}
   		else {
   			l = mid;
   		}
   	}
   	cout << fixed << setprecision(10) << (l + r) / 2 << '\n';
   }
   return 0;
}