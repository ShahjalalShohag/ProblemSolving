#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
string s[N];

struct node {
    node* nxt[26];
    int dp[26];
    node() { 
    	for (int i = 0; i < 26; i++) nxt[i] = NULL; 
    	memset(dp, 0, sizeof dp);
    }
}*root;

void add(string &s) {
    node* cur = root;
    int n = s.size();
    vector<node*> pref(n);
    for (int i = 0; i < n; i++) {
    	pref[i] = cur;
        int b = s[i] - 'a';
        if (cur -> nxt[b] == NULL) cur -> nxt[b] = new node();
        cur = cur -> nxt[b];
    }
    vector<int> cnt(26, 0);
    for (int i = n - 1; i >= 0; i--) {
    	cnt[s[i] - 'a']++;
    	for (int j = 0; j < 26; j++) {
	    	if (cnt[j]) {
	    		pref[i] -> dp[j]++;
	    	}
	    }
    }
}

int yo(string &s) {
    node* cur = root;
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        int b = s[i] - 'a';
        cur = cur -> nxt[b];
    }
    return cur -> dp[s.back() - 'a'];
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	root = new node();
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
		add(s[i]);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += yo(s[i]) - 1;
	}

	cout << ans << '\n';
    return 0;
}