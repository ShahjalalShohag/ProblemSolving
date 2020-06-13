#include<bits/stdc++.h>
using namespace std;
 
const int N = 3000;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int query(int i, int j) {
	if (i == j) while(1);
	cout << "? " << i << ' ' << j << '\n';
	cout.flush();
	int k; cin >> k;
	return k;
}
int a[N], n;
void yo(int id) {
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);
	shuffle(p.begin(), p.end(), rnd);
	set<int> se;
	for (auto i: p) if (i != id) {
        a[i] = query(i, id);
        if (se.find(a[i]) != se.end() || a[i] >= n) return;
        se.insert(a[i]);
	}
	int z = 0;
	while(se.find(z) != se.end()) z++;
	a[id] = z;
	cout << "!";
	for (int i = 1; i <= n; i++) cout << " " << a[i];
	cout << '\n';
	cout.flush();
	exit(0);
}
int32_t main() {
	cin >> n;
	int id;
	while (1) {
		int i = rnd() % n + 1, j = rnd() % n + 1;
		if (i == j) continue;
		int k = query(i, j);
		if (__builtin_popcount(k) <= 6) {
			id = i; break;
		}
	}
	vector<int> cand;
	int mn = 1e9;
	for (int i = 1; i <= n; i++) {
		if (i != id) a[i] = query(id, i), mn = min(mn, a[i]);
	}
	a[id] = mn;
	if (a[id] == 0) yo(id);
	for (int i = 1; i <= n; i++) {
		if (a[i] == mn) cand.push_back(i);
	}
	shuffle(cand.begin(), cand.end(), rnd);
	for (auto x: cand) {
		set<int> se;
		for (auto y: cand) if (x != y) se.insert(query(x, y));
		if (se.size() == (int)cand.size() - 1) yo(x);
	}
	while(1);
    return 0;
}