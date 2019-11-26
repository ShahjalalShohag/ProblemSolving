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
const int mod = 998244353;
const int root=3;

int lim, rev[N], w[N], wn[N],inv_lim;
void reduce(int &x) { x=(x+mod)%mod;}
int pow(int x, int y, int ans = 1)
{
	for (; y; y >>= 1, x = (ll) x * x % mod)
		if (y & 1) ans = (ll) ans * x % mod;
	return ans;
}
void nttinit(int len)
{
	lim = wn[0] = 1;
	int s = -1;
    while (lim < len) lim <<= 1, ++s;
	for (int i = 0; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
	const int g = pow(root, (mod - 1) / lim);
	inv_lim=pow(lim, mod - 2);
	for (int i = 1; i < lim; ++i) wn[i] = (ll) wn[i - 1] * g % mod;
}
void ntt(vector<int> &a, int typ)
{
	for (int i = 0; i < lim; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 1; i < lim; i <<= 1) {
		for (int j = 0, t = lim / i / 2; j < i; ++j) w[j] = wn[j * t];
		for (int j = 0; j < lim; j += i << 1)
			for (int k = 0; k < i; ++k) {
				const int x = a[k + j], y = (ll) a[k + j + i] * w[k] % mod;
				reduce(a[k + j] += y - mod), reduce(a[k + j + i] = x - y);
			}
	}
	if (!typ) {
        reverse(a.begin() + 1, a.begin() + lim);
		for (int i = 0; i < lim; ++i) a[i] = (ll) a[i] * inv_lim % mod;
	}
}
vector<int> multiply(vector<int> &f, vector<int> &g)
{
    int n=(int)f.size()+(int)g.size()-1;
    nttinit(n);
    vector<int> a=f,b=g;
    a.resize(lim);
    b.resize(lim);
    ntt(a, 1), ntt(b, 1);
    for (int i = 0; i < lim; ++i) a[i] = (ll) a[i] * b[i] % mod;
    ntt(a, 0);
    while((int)a.size()&&a.back()==0) a.pop_back();
    return a;
}
vector<int> pow(vector<int> a, int k)
{
    vector<int> ans;
    ans.eb(1);
    while(k){
        if(k&1) ans=multiply(ans,a);
        a=multiply(a,a);
        k>>=1;
    }
    return ans;
}
int a[N];
int32_t main()
{
    int n=in(), k=in();
    for(int i=0; i<n; i++) a[i]=in();
    a[n]=a[0];
    int ty1=0,ty2=0;
    for(int i=0; i<n; i++){
        if(a[i]==a[i+1]) ty1++;
        else ty2++;
    }
    vector<int> ans(3);
    ans[0]=1;
    ans[1]=k-2;
    ans[2]=1;
    ans=pow(ans, ty2);
    int kp=1;
    for(int i=0; i<ty1; i++) kp=1LL*kp*k%mod;
    for(int i=0; i<(int) ans.size(); i++) ans[i]=1LL*ans[i]*kp%mod;
    vector<int> fnal(2*n+1,0);
    for(int i=n+1; i<2*n+1; i++) fnal[i]=1;
    ans= multiply(ans, fnal);
    int res=0;
    if(n+ty2<(int)ans.size()) res=ans[n+ty2];
    printf("%d\n", res);
    return 0;
}
