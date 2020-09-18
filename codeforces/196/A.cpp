#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

int nxt[N][26];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	int n = s.size();

	memset(nxt, -1, sizeof nxt);
	for (int i = n - 1; i >= 0; i--) {
		for (int k = 0; k < 26; k++) {
			nxt[i][k] = nxt[i + 1][k];
		}
		nxt[i][s[i] - 'a'] = i;
	}
	string ans = "";
	for (int i = 0; i < n; ) {
		int k = -1;
		for (int j = 25; j >= 0; j--) {
			if (nxt[i][j] != -1) {
				k = nxt[i][j];
				break;
			}
		}
		if (k == -1) break;
		ans += s[k];
		i = k + 1;
	}
	cout << ans << '\n';
    return 0;
}