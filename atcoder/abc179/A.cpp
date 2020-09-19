#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	if (s.back() == 's') cout << s + "es";
	else cout << s + "s";
    return 0;
}