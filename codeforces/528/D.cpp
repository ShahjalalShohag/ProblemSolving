#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

const long double PI = acos(-1);
struct base {
	long double a, b;
	base(long double a = 0, long double b = 0) : a(a), b(b) {}
	const base operator + (const base &c) const
		{ return base(a + c.a, b + c.b); }
	const base operator - (const base &c) const
		{ return base(a - c.a, b - c.b); }
	const base operator * (const base &c) const
		{ return base(a * c.a - b * c.b, a * c.b + b * c.a); }
};
void fft(vector<base> &p, bool inv = 0) {
	int n = p.size(), i = 0;
	for(int j = 1; j < n - 1; ++j) {
		for(int k = n >> 1; k > (i ^= k); k >>= 1);
		if(j < i) swap(p[i], p[j]);
	}
	for(int l = 1, m; (m = l << 1) <= n; l <<= 1) {
		long double ang = 2 * PI / m;
		base wn = base(cos(ang), (inv ? 1. : -1.) * sin(ang)), w;
		for(int i = 0, j, k; i < n; i += m) {
			for(w = base(1, 0), j = i, k = i + l; j < k; ++j, w = w * wn) {
				base t = w * p[j + l];
				p[j + l] = p[j] - t;
				p[j] = p[j] + t;
			}
		}
	}
	if(inv) for(int i = 0; i < n; ++i) p[i].a /= n, p[i].b /= n;
}
vector<int> multiply(vector<int> &a, vector<int> &b) {
	int n = a.size(), m = b.size(), t = n + m - 1, sz = 1;
	while(sz < t) sz <<= 1;
	vector<base> x(sz), y(sz), z(sz);
	for(int i = 0 ; i < sz; ++i) {
		x[i] = i < a.size() ? base(a[i], 0) : base(0, 0);
		y[i] = i < b.size() ? base(b[i], 0) : base(0, 0);
	} fft(x), fft(y);
	for(int i = 0; i < sz; ++i) z[i] = x[i] * y[i];
	fft(z, 1);
	vector<int> ret(sz);
	for(int i = 0; i < sz; ++i) ret[i] = z[i].a + 0.5;
	while(ret.size() > 1 && ret.back() == 0) ret.pop_back();
	return ret;
}
int ans[N];
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k ; cin >> n >> m >>k;
    string a, b; cin >> a >> b;
    vector<char> c = {'A', 'C', 'G', 'T'};
    for(auto ch : c){
        vector<int> A(n, 0), B(m, 0), st(n + 1, 0);
        for(int i = 0; i < n; i++) if(a[i] == ch) A[i] = 1, st[max(0, i - k)] ++, st[min(n, i + k + 1)] --;
        for(int i = 0; i < m; i++) if(b[i] == ch) B[i] = 1;
        for(int i = 0; i < n; i++){
            if(i) st[i] += st[i - 1];
            if(st[i]) A[i] = 1;
        }
        reverse(B.begin(), B.end());
        B.resize(n);
        auto nw = multiply(A, B);
        for(int i = m - 1; i < n; i++) if(i < (int)nw.size()) ans[i] += nw[i];
    }
    int res = 0;
    for(int i = m - 1; i < n; i++) if(ans[i] == m) res++;
    cout << res << nl;
    return 0;
}
