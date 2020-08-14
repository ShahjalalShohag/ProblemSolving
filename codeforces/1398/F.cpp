#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int p[2][N];
bool yo(int l, int r) {
	int a = p[0][r] - (l ? p[0][l - 1] : 0);
	int b = p[1][r] - (l ? p[1][l - 1] : 0);
	if (a && b) return false;
	return true;
}
vector<int> id[2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] != '?') {
			id[s[i] - '0'].push_back(i);
			p[s[i] - '0'][i]++;
		}
		if (i) {
			for (int k = 0; k < 2; k++) p[k][i] += p[k][i - 1];
		}
	}
	for (int k = 1; k <= n; k++) {
		int ans = 0;
		int i = 0, last0 = 0, last1 = 0;
		while (n - i >= k) {
			int l = i + k - 1, r = n - 1, cur = -1;
			if (yo(i, l)) {
				while (l <= r) {
					int mid = l + r >> 1;
					if (yo(i, mid)) cur = mid, l = mid + 1;
					else r = mid - 1;
				}
			}
			if (cur == -1) {
				int f = upper_bound(id[0].begin() + last0, id[0].end(), i + k - 1) - id[0].begin() - 1;
				int g = upper_bound(id[1].begin() + last1, id[1].end(), i + k - 1) - id[1].begin() - 1;
				last0 = f;
				last1 = g;
				f = id[0][f];
				g = id[1][g];
				i = min(f, g) + 1;
			}
			else {
				ans += (cur - i + 1) / k;
				cur -= (cur - i + 1) % k;
				i = cur + 1;
			}
		}
		cout << ans << ' ';
	}
    return 0;
}