#include<bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct treap {
    struct node {
        int val, ans, id, sz, prior, lazy_ans, lazy_val, mx, mn;
        node *l, *r, *par;
        node(int _val, int _id) {
            val = _val; mx=_val; mn=_val; ans = 0; id = _id;
            lazy_ans = 0; lazy_val = 0; sz = 1;
            prior = rnd(); l = NULL; r = NULL; par = NULL;
        }
    };
    typedef node* pnode;
    pnode root;
    void clear() {
        root = NULL;
    }
    treap() {
        clear();
    }
    int size(pnode t) {
        return t ? t->sz : 0;
    }
    void update_size(pnode &t) {
        if(t) t->sz = size(t->l) + size(t->r) + 1;
    }

    void update_parent(pnode &t) {
        if(!t) return;
        if(t->l) t->l->par = t;
        if(t->r) t->r->par = t;
    }
    ///add operation
    void push(pnode &t) {
        if(!t)  return;
        if (t->lazy_ans == 0 && t->lazy_val == 0) return;
        t->ans += t->lazy_ans;
        t->val += t->lazy_val;
        t->mx += t->lazy_val;
        t->mn += t->lazy_val;
        if(t->l) {
        	t->l->lazy_ans += t->lazy_ans;
        	t->l->lazy_val += t->lazy_val;
        }
        if(t->r) {
        	t->r->lazy_ans += t->lazy_ans;
        	t->r->lazy_val += t->lazy_val;
        }
        t->lazy_ans = 0;
        t->lazy_val = 0;
    }
    void reset(pnode &t) {
        if(!t) return;
        t->mx = t->val;
        t->mn = t->val;
    }
    ///combine node l and r to form t by updating corresponding queries
    void combine(pnode &t, pnode l, pnode r) {
        if(!l) {
            t = r; return;
        }
        if(!r) {
            t = l; return;
        }
        t->mx = max(l->mx,r->mx);
        t->mn = min(l->mn,r->mn);
    }
    ///perform all operations
    void operation(pnode &t) {
        if(!t)    return;
        reset(t);
        push(t->l);
        push(t->r);
        combine(t, t->l, t);
        combine(t, t, t->r);
    }
    void split(pnode t, pnode &l, pnode &r, int k) {
        if(t == NULL) {
            l = NULL;
            r = NULL;
            return;
        }
        push(t);
        if(t -> val <= k)
            split(t->r, t->r, r, k), l = t;
        else
            split(t->l, l, t->l, k), r = t;

        update_parent(t);
        update_size(t);
        operation(t);
    }
    ///merge node l with r in t
    void merge(pnode &t, pnode l, pnode r) {
        push(l);
        push(r);
        if(!l) {
            t = r;
            return;
        }
        if(!r) {
            t = l;
            return;
        }

        if(l->prior > r->prior)
            merge(l->r, l->r, r), t = l;
        else
            merge(r->l, l, r->l), t = r;

        update_parent(t);
        update_size(t);
        operation(t);
    }
    void insert(int val, int id) {
        if(root == NULL) {
            pnode to_add = new node(val, id);
            root = to_add;
            return;
        }

        pnode l, r, mid;
        mid = new node(val, id);

        split(root, l, r, val);
        merge(l, l, mid);
        merge(root, l, r);
    }
    void upd(int k) {
    	pnode l, r, tmp, z; 
    	split(root, l, r, k - 1);
    	if (r == NULL) {
    		merge(root, l, r);
    		return;
    	}
    	r -> lazy_ans++;
    	r -> lazy_val -= k;
    	push(r);
    	operation(r);
    	while (l != NULL && r != NULL) {
    		if (l -> mx <= r -> mn) break;
    		int x = r->mn;
    		split(r, tmp, r, x);
    		split(l, l, z, x);
    		merge(l, l, tmp);
    		merge(l, l, z);
    	}
    	merge(root, l, r);
    }
    vector<int> res;
    void inorder(pnode cur) {
        if(cur==NULL) return;
        operation(cur);
        res[cur ->id] = cur -> ans;
        inorder(cur->l);
        inorder(cur->r);
    }
};

treap t;

const int N = 2e5 + 9;
array<int, 2> a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][0];
		a[i][0] *= -1;
	}
	sort(a + 1, a + n + 1);
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int k; cin >> k;
		t.insert(k, i);
	}
	for (int i = 1; i <= n; i++) {
		int k = a[i][1];
		t.upd(k);
	}
	t.res.resize(q + 1);
	t.inorder(t.root);
	for (int i = 1; i <= q; i++) {
		cout << t.res[i] << ' ';
	}
    return 0;
}