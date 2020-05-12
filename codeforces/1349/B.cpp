#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int N = 3e6 + 9;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int cnt = 0;
		for (int i = 1; i <= n; i++) cin >> a[i], cnt += a[i] == k;
		int ok = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] >= k && a[i + 1] >= k) ok = 1;
			if (i + 2 <= n && a[i] >= k && a[i + 1] < k && a[i + 2] >= k) ok = 1;
		}
		if (cnt && (cnt == n || ok)) cout << "yes\n";
		else cout << "no\n";
	}
    return 0;
}