#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
const int kinds = N;///maximum ASCII value of any character of the string
int str[N];
int K, buc[N], r[N], sa[N], X[N], Y[N], high[N];
bool cmp(int *r, int a, int b, int x)
{
    return (r[a] == r[b] && r[a+x] == r[b+x]);
}

void suffix_array_DA(int n, int m)
{
    int *x = X, *y = Y, i, j, k = 0, l;
    memset(buc, 0, sizeof(buc));
    for(i = 0; i < n; i++) buc[ x[i]=str[i] ]++;
    for(i = 1; i < m; i++) buc[i] += buc[i-1];
    for(i = n-1; i >= 0; i--) sa[--buc[x[i]]] = i;
    for(l = 1, j = 1; j < n; m = j, l <<= 1)
    {
        j = 0;
        for(i = n-l; i < n; i++) y[j++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= l) y[j++] = sa[i]-l;
        for(i = 0; i < m; i++) buc[i] = 0;
        for(i = 0; i < n; i++) buc[ x[y[i]] ]++;
        for(i = 1; i < m; i++) buc[i] += buc[i-1];
        for(i = n-1; i >= 0; i--) sa[ --buc[ x[y[i]] ]] = y[i];
        for(swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l) ? j-1 : j++;
    }
    for(i = 1; i < n; i++) r[sa[i]] = i;
    for(i = 0; i < n-1; high[r[i++]] = k)
        for(k ? k--: 0, j = sa[r[i]-1]; str[i+k] == str[j+k]; k++);
}
vector<int> suffix_array_construction(vector<int> s)
{
    int n=s.size();
    for(int i=0;i<n;i++) str[i]=s[i];
    str[n]= 0;
    suffix_array_DA(n+1,kinds);
    vector<int>saa;
    for(int i=1;i<=n;i++) saa.push_back(sa[i]);
    return saa;
}
int t[N][18], a[N];
void build(int n) {
    for(int i = 1; i <= n; ++i) t[i][0] = a[i];
    for(int k = 1; k < 18; ++k) {
            for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
                    t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
            }
    }
}

int query(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return min(t[l][k], t[r - (1 << k) + 1][k]);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	auto sa = suffix_array_construction(p);
    for (int i = 0; i < n; i++) a[sa[i] + 1] = i + 1;
    build(n);
	for (int i = 1; i <= n; i++) {
		int l = i, r = n, ans = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(i, mid) >= a[i]) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << '\n';
	}
    return 0;
}