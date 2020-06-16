#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

// len -> largest string length of the corresponding endpos-equivalent class
// link -> longest suffix that is another endpos-equivalent class.
// firstpos -> 1 indexed end position of the first occurrence of the largest string of that node
// minlen(v) -> smallest string of node v = len(link(v)) + 1
// terminal nodes -> store the suffixes
struct SuffixAutomaton {
    struct node {
        int len, link, firstpos;
        map<char, int> nxt;
    };
    int sz, last;
    vector<node> t;
    vector<int> terminal;
    vector<long long> dp;
    SuffixAutomaton() {}
    SuffixAutomaton(int n) {
        t.resize(2 * n); terminal.resize(2 * n);
        dp.resize(2 * n, -1); sz = 1; last = 0;
        t[0].len = 0; t[0].link = -1; t[0].firstpos = 0;
    }
    void extend(char c) {
        int p = last;
    	if (t[p].nxt.count(c)) {
            int q = t[p].nxt[c];
            if (t[q].len == t[p].len + 1) {
                last = q;
                return;
            }
            int clone = sz++;
            t[clone] = t[q];
            t[clone].len = t[p].len + 1;
            t[q].link = clone;
            last = clone;
            while (p != -1 && t[p].nxt[c] == q) {
                t[p].nxt[c] = clone;
                p = t[p].link;
            }
            return;
        }
        int cur = sz++;
        t[cur].len = t[last].len + 1;
        t[cur].firstpos = t[cur].len;
        p = last;
        while (p != -1 && !t[p].nxt.count(c)) {
            t[p].nxt[c] = cur;
            p = t[p].link;
        }
        if (p == -1) t[cur].link = 0;
        else {
            int q = t[p].nxt[c];
            if (t[p].len + 1 == t[q].len) t[cur].link = q;
            else {
                int clone = sz++;
                t[clone] = t[q];
                t[clone].len = t[p].len + 1;
                while (p != -1 && t[p].nxt[c] == q) {
                    t[p].nxt[c] = clone;
                    p = t[p].link;
                }
                t[q].link = t[cur].link = clone;
            }
        }
        last = cur;
    }
};

string s[N];
int cnt[N], ans[N], vis[N];
vector<int> all[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	SuffixAutomaton sa(N);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sa.last = 0;
		for (auto c: s[i]) sa.extend(c);
	}
	for (int i = 0; i < n; i++) {
		sa.last = 0;
		for (auto c: s[i]) {
			sa.extend(c);
			for (int cur = sa.last; cur != -1; cur = sa.t[cur].link) {
				if (vis[cur]) break;
				cnt[cur]++;
				vis[cur] = 1;
			}
		}		
		sa.last = 0;
		for (auto c: s[i]) {
			sa.extend(c);
			for (int cur = sa.last; cur != -1; cur = sa.t[cur].link) {
				if (!vis[cur]) break;
				vis[cur] = 0;
			}
		}
	}
	for (int i = 1; i < sa.sz; i++) all[sa.t[i].len].push_back(i);
	for (int i = 1; i <= sa.sz; i++) {
		for (auto p: all[i]) {
			if (cnt[p] >= k) ans[p] = sa.t[p].len;
			else ans[p] = ans[sa.t[p].link];
		}
	}
	for (int i = 0; i < n; i++) {
		sa.last = 0;
		long long res = 0;
		for (auto c: s[i]) {
			sa.extend(c);
			res += ans[sa.last];
		}
		cout << res << ' ';
	}
    return 0;
}