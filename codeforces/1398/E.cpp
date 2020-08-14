#include<bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct node {
    node *l, *r;
    int key, prior, cnt;
    long long sum;
    node(int id) {
        l = r = nullptr;
        key = id; prior = rnd();
        cnt = 1;
        sum = id;
    }
};
struct treap {
    node *root;
    treap() {
        root = nullptr;
    }
    long long sum(node* t) {return t ? t->sum : 0;}
	int cnt(node* t) {return t ? t->cnt : 0;}
	void upd_cnt(node* t) {
		if (!t) return;
		t->cnt = cnt(t->l) + cnt(t->r) + 1;
		t->sum = sum(t->l) + sum(t->r) + t->key;
	}
    void split(node *t, int pos, node *&l, node *&r) {
        if (t == nullptr) {
            l = r = nullptr;
            return;
        }
        if (t->key <= pos) {
            split(t->r, pos, l, r);
            t->r = l; l = t;
        } 
        else {
            split(t->l, pos, l, r);
            t->l = r; r = t;
        }
        upd_cnt(t);
    }
    node* merge(node *l, node *r) {
        if (!l || !r) return l ? l : r;
        if (l->prior < r->prior) {
            l->r = merge(l->r, r);
            upd_cnt(l);
            return l;
        }
        r->l = merge(l, r->l);
        upd_cnt(r);
        return r;
    }
    void insert(int id) {
        node *l, *r;
        split(root, id, l, r);
        root = merge(merge(l, new node(id)), r);
    }
    node* erase(int L, int R) {
        node *l, *r, *mid, *mr;
        split(root, L - 1, l, r);
        split(r, R, mid, mr);
        root = merge(l, mr);
        return mid;
    }
	long long yo(node* t, int k) {
		if (!k) return 0;
		if (cnt(t) <= k) return t->sum;
		if (cnt(t->r) >= k) return yo(t->r, k);
		if (cnt(t->r) + 1 == k) return sum(t->r) + t->key;
		return sum(t->r) + t->key + yo(t->l, k - cnt(t->r) - 1);
	}
} t;
set<int> se[2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	long long tot = 0;
	while (n--) {
		int ty, k; cin >> ty >> k;
		if (k > 0) se[ty].insert(k), t.insert(k), tot += k;
		else k *= -1, se[ty].erase(k), t.erase(k, k), tot -= k;
		if (tot == 0) {
			cout << 0 << '\n';
			continue;
		}
		int cur = se[1].size();
		if (cur == 0) {
			cout << tot << '\n';
			continue;
		}
		long long ans = tot + t.yo(t.root, cur);
		if (se[0].empty()) {
			ans -= *se[1].begin();
		}
		else if ((*se[0].rbegin()) < (*se[1].begin())) {
			ans -= *se[1].begin();
			ans += *se[0].rbegin();
		}
		cout << ans << '\n';
	}
    return 0;
}