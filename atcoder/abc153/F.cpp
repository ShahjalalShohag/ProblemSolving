#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;
const ll inf = 9e18;

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
int32_t main()
{
    BIT<ll> t;
    t.init(N);
    int n = in(), d = in(), p = in();
    vector<pll> v(n);
    for(auto &x: v) x.first = in(), x.second = in();
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i =0 ; i<n; i++){
        ll nw = v[i].second + t.query(i+1);
        if(nw > 0){
            int k = upper_bound(v.begin() + i, v.end(), make_pair(1LL*v[i].first + 2LL*d, inf)) - v.begin();
            t.upd(i+1, k, max(-1000000100LL, -(nw + p -1) / p * p));
            ans += (nw + p -1)/p;
        }
    }
    cout << ans << nl;
    return 0;
}
