#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a) x /= n;
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
    return result;
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
