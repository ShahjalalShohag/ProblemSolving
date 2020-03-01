#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 5e5 + 9;
const int mod = 1e9 + 7;

template <class T>
struct BIT
{
    ///1-indexed
	int sz;
	vector<T> t;

	void init(int n) ///max size of array
	{
		sz = n;
		t.assign(sz,0);
	}

	T query(int idx)
	{
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx)) ans += t[idx];
		return ans;
	}

	void upd(int idx, T val)
	{
		if(idx <= 0) return;
		for(; idx <sz; idx += (idx & -idx)) t[idx] += val;
	}

	void upd(int l, int r, T val)
	{
	    upd(l,val);
	    upd(r+1,-val);
	}

	T query(int l, int r) { return query(r) - query(l - 1); }
};
BIT<int> t[26];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 26; i++) t[i].init(N);
    int n; cin >> n;
    string s; cin >> s;
    s = "#" + s;
    for(int i = 1; i <= n; i++){
        t[s[i] - 'a'].upd(i, 1);
    }
    int q; cin >> q;
    while(q--){
        int ty; cin >> ty;
        if(ty == 1){
            int i; char ch; cin >> i >> ch;
            t[s[i] - 'a'].upd(i, -1);
            s[i] = ch;
            t[s[i] - 'a'].upd(i, 1);
        }
        else{
            int l, r; cin >> l >> r;
            int ans = 0;
            for(int k = 0; k < 26; k++){
                ans += t[k].query(l, r) > 0;
            }
            cout << ans << nl;
        }
    }
    return 0;
}

