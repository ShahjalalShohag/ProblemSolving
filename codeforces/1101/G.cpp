#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
struct Basis {
	vector<int> a;
	void insert(int x) {
	    for (auto &i: a) x = min(x, x ^ i);
	    if (!x) return;
	    for (auto &i: a) if((i ^ x) < i) i ^= x;
	    a.push_back(x);
	    sort(a.begin(), a.end());
	}
	bool can(int x) {
	    for(auto &i: a) x = min(x, x ^ i);
	    return !x;
	}
	int maxxor(int x = 0) {
	    for (auto &i: a) x = max(x, x ^ i);
		return x;
	}	
	int minxor(int x = 0) {
	    for (auto &i: a) x = min(x, x ^ i);
		return x;
	}
	int kth(int k) { // 1st is 0
	    int sz = (int)a.size();
	    if (k > (1 << sz)) return -1;
	    k--; int ans = 0;
	    for(int i = 0; i < sz; i++) if(k >> i & 1) ans ^= a[i];
	    return ans;
	}
}t;
int a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
    	int k; cin >> k;
    	a[i] = a[i - 1] ^ k;
    	t.insert(a[i]);
    }
    if (!a[n - 1]) cout << -1 << '\n';
    else cout << t.a.size() << '\n';
    return 0;
}