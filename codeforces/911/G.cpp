#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 9;

struct node {
	node *l, *r;
	int pos, key, sz = 0;
	node(int position) {
		l = r = nullptr;
		pos = position;
		key = rnd();
	}
	void pull()
	{
	    sz = 1;
	    if(l) sz += l -> sz;
	    if(r) sz += r -> sz;
	}
};
struct treap
{
	node *root;
	treap() {
		root = nullptr;
	}
	void split(node *t, int pos, node *&l, node *&r)
	{
		if (t == nullptr) {
			l = r = nullptr;
			return;
		}
		if (t->pos < pos) {
			split(t->r, pos, l, r);
			t->r = l;
			l = t;
		}
		else {
			split(t->l, pos, l, r);
			t->l = r;
			r = t;
		}
		t -> pull();
	}
	node* merge(node *l, node *r)
	{
		if (!l || !r) return l ? l : r;
		if (l->key < r->key) {
			l->r = merge(l->r, r);
			l -> pull();
			return l;
		}
		r->l = merge(l, r->l);
		r -> pull();
		return r;
	}
	node* merge_op(node *l, node *r)
    {
        if(!l) { return r;}
        if(!r) { return l;}
        if(l->key < r->key) swap(l, r);
        node *L, *R;
        split(r, l->pos, L, R);
        l->r = merge_op(l->r, R);
        l->l = merge_op(L, l->l);
        l -> pull();
        return l;
    }
	void insert(int pos)
	{
		node *l, *r;
        split(root, pos, l, r);
        root = merge(merge(l, new node(pos)), r);
	}
	node* erase(int L, int R)
	{
        node *l, *r, *mid, *mr;
        split(root, L, l, r);
        split(r, R + 1, mid, mr);
        root = merge(l, mr);
        return mid;
	}
	void combine(node *x)
	{
        root = merge_op(root, x);
	}
	vector<int> ans;
	void dfs(node* cur)
	{
	    if(!cur) return;
	    ans.push_back(cur -> pos);
        dfs(cur -> l);
        dfs(cur -> r);
	}
	vector<int> get()
	{
	    ans.clear();
	    dfs(root);
	    return ans;
	}
}t[N];
int ans[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int k; cin >> k; t[k].insert(i);
    }
    int q; cin >> q;
    while(q--){
        int l, r, x, y; cin >> l >> r >> x >> y;
        node* p = t[x].erase(l, r);
        t[y].combine(p);
    }
    for(int i = 1; i < N; i++){
        auto p = t[i].get();
        for(auto x: p) ans[x] = i;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}
