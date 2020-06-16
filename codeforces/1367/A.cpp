#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		cout << s[0] << s[1];
		for (int i = 3; i < s.size(); i += 2) cout << s[i];
		cout << '\n';
	}
    return 0;
}