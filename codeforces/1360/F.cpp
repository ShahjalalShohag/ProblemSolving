#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

string s[20];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int j = 0; j < m; j++) {
			for (char ch = 'a'; ch <= 'z'; ch++) {
				char p = s[0][j];
				s[0][j] = ch;
				int ok = 1;
				for (int i = 0; i < n; i++) {
					int dif = 0;
					for (int j = 0; j < m; j++) dif += s[0][j] != s[i][j];
					ok &= dif <= 1;
				}
				if (ok) {
					cout << s[0] << '\n';
					goto hell;
				}
				s[0][j] = p;
			}
		}
		cout << "-1\n";
		hell:
        int z;
	}
    return 0;
}
