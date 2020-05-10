#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t; cin >> s >> t;
	t.pop_back();
	if (s== t) cout << "Yes\n";
	else cout << "No\n";
    return 0;
}