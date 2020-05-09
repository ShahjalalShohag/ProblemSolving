#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		if (!a && !b) cout << string(c + 1, '1') << '\n';
		else if(!c && !b) cout << string(a + 1, '0') << '\n';
		else {
			string s = string(c + 1, '1') + string(a + 1, '0');
			b--;
			while (b > 0) s += s.back() == '0' ? '1' : '0', b--;
			cout << s << '\n';
		}
	}
    return 0;
}