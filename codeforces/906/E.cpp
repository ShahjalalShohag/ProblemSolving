#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

/*
-> diff(v) = len(v) - len(link(v))
-> series link will lead from the vertex v to the vertex u corresponding
   to the maximum suffix palindrome of v which satisfies diff(v) != diff(u)
-> path within series links to the root contains only O(log n) vertices
-> cnt constains the number of palindromic suffixes of the node
*/
struct PalindromicTree {
    struct node {
        int nxt[26], len, st, en, link, diff, slink, cnt, oc;
    };
    string s; vector<node> t;
    int sz, last;
    PalindromicTree() {}
    PalindromicTree(string _s) {
        s = _s; int n = s.size();
        t.clear(); t.resize(n + 9);
        sz = 2, last = 2;
        t[1].len = -1, t[1].link = 1;
        t[2].len = 0, t[2].link = 1;
        t[1].diff = t[2].diff = 0;
        t[1].slink = 1; t[2].slink = 2;
    }
    int extend(int pos) { // returns 1 if it creates a new palindrome
        int cur = last, curlen = 0;
        int ch = s[pos] - 'a';
        while (1) {
            curlen = t[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) break;
            cur = t[cur].link;
        }
        if (t[cur].nxt[ch]) {
            last = t[cur].nxt[ch];
            t[last].oc++;
            return 0;
        }
        sz++; last = sz;
        t[sz].oc = 1; t[sz].len = t[cur].len + 2;
        t[cur].nxt[ch] = sz;
        t[sz].en = pos; t[sz].st = pos - t[sz].len + 1;
        if (t[sz].len == 1) {
            t[sz].link = 2; t[sz].cnt = 1;
            t[sz].diff = 1; t[sz].slink = 2;
            return 1;
        }
        while (1) {
            cur = t[cur].link; curlen = t[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
                t[sz].link = t[cur].nxt[ch];
                break;
            }
        }
        t[sz].cnt = 1 + t[t[sz].link].cnt;
        t[sz].diff = t[sz].len - t[t[sz].link].len;
        if (t[sz].diff == t[t[sz].link].diff) t[sz].slink = t[t[sz].link].slink;
        else t[sz].slink = t[sz].link;
        return 1;
    }
    void calc_occurrences() {
        for (int i = sz; i >= 3; i--) t[t[i].link].oc += t[i].oc;
    }
} t;

int ans[N], series_mn[N], par[N];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b; cin >> a >> b;
    string s = "";
    for (int i = 0; i < a.size(); i++) s += a[i], s += b[i];
    PalindromicTree t(s);
	int n = s.size();
	for (int i = 1; i <= n; i++) {
		t.extend(i - 1);
		ans[i] = 1e9;
		for (int v = t.last; t.t[v].len > 0; v = t.t[v].slink) {
            series_mn[v] = i - (t.t[t.t[v].slink].len + t.t[v].diff);
            if (t.t[v].diff == t.t[t.t[v].link].diff) {
            	if (ans[series_mn[v]] > ans[series_mn[t.t[v].link]]) series_mn[v] = series_mn[t.t[v].link];
            }
            if (i % 2 == 0 && ans[series_mn[v]] + 1 < ans[i]) {
				ans[i] = ans[series_mn[v]] + 1;
				par[i] = series_mn[v];
			}
        }
		if (i % 2 == 0 && s[i - 1] == s[i - 2] && ans[i - 2] < ans[i]) ans[i] = ans[i - 2], par[i] = -1;
	}
	if (ans[n] == 1e9) return cout << -1 << '\n', 0;
	cout << ans[n] << '\n';
	for (int cur = n; cur; ) {
		if (par[cur] == -1) cur -=2;
		else cout << (par[cur] >> 1) + 1 << ' ' << (cur >> 1) << '\n', cur = par[cur];
	}
    return 0;
}
