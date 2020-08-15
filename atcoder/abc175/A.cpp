#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	if (s[0] == 'R' && s[1] == 'R' && s[2] == 'R') cout << 3 << '\n';
	else if (s[0] == 'R' && s[1] == 'R' || s[1] == 'R' && s[2] == 'R') cout << 2 << '\n';
	else if (s[0] == 'R' || s[1] == 'R' || s[2] == 'R') cout << 1 << '\n';
	else cout << 0 << '\n';
    return 0;
}