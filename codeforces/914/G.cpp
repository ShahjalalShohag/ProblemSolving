#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 1<<17;
const int mod = 1e9 + 7;

int qpow(int n, int k)
{
    int ans=1;
    while(k){
        if(k&1) ans=1LL*ans*n%mod;
        n=1LL*n*n%mod;
        k>>=1;
    }
    return ans;
}
#define MX (1 << 17)
#define OR 0
#define AND 1
#define XOR 2
int in=qpow(2,mod-2);
///Fast Walsh-Hadamard Transformation in n log n
///Beware!!! after the convolution the arrays will not be the same again
///array sizes must be same and powers of 2
struct fwht{
    int P1[MX], P2[MX],P3[MX];

    void walsh_transform(int* ar, int n, int flag = AND){
        if (n == 0) return;

        int i, m = n/2;
        walsh_transform(ar, m, flag);
        walsh_transform(ar+m, m, flag);

        for (i = 0; i < m; i++){  /// Don't forget to remove modulo if not required
            int x = ar[i], y = ar[i + m];
            if (flag == OR) ar[i] = x, ar[i + m] = (x + y)%mod;
            if (flag == AND) ar[i] = (x + y)%mod, ar[i + m] = y;
            if (flag == XOR) ar[i] = (x + y)%mod, ar[i + m] = (x - y+mod)%mod;
        }
    }

    void inverse_walsh_transform(int* ar, int n, int flag = AND){
        if (n == 0) return;

        int i, m = n/2;
        inverse_walsh_transform(ar, m, flag);
        inverse_walsh_transform(ar+m, m, flag);

        for (i = 0; i < m; i++){  /// Don't forget to remove modulo if not required
            int x = ar[i], y = ar[i + m];
            if (flag == OR) ar[i] = x, ar[i + m] = (y - x+mod)%mod;
            if (flag == AND) ar[i] = (x - y+mod)%mod, ar[i + m] = y;
            if (flag == XOR) ar[i] = 1LL*(x + y)%mod *in%mod, ar[i + m] = 1LL*(x - y+mod)%mod *in%mod; ///replace modular inverse(in) by >>1 if not required
        }
    }

    /// For i = 0 to n - 1, j = 0 to n - 1
    /// v[i flag j] += A[i] * B[j]
    vector<int> convolution(int n, int* A, int* B, int flag = AND){
        assert(__builtin_popcount(n) == 1); /// n must be a power of 2
        for (int i = 0; i < n; i++) P1[i] = A[i];
        for (int i = 0; i < n; i++) P2[i] = B[i];

        walsh_transform(P1, n, flag);
        walsh_transform(P2, n, flag);
        for (int i = 0; i < n; i++) P1[i] = 1LL*P1[i] * P2[i]%mod;
        inverse_walsh_transform(P1, n, flag);
        return vector<int>(P1,P1+n);
    }

    ///compute A^k where A*A=A convolution A
    vector<int> pow(int n,int* A,ll k,int flag=AND)
    {
        walsh_transform(A,n,flag);
        for(int i=0;i<n;i++) A[i]=qpow(A[i],k);
        inverse_walsh_transform(A,n,flag);
        return vector<int>(A,A+n);
    }
}t;
///s' $ s defines all subsets of s
struct SOS
{
    const int B=17;///Every input vector must need to be of size 1<<B

    /// z(f(s))=\sum_{s' $ s}{f(s')}
    ///O(B * 2 ^ B)
    ///zeta transform is actually SOS DP
    vector<int> zeta_transform(vector<int> f)
    {
        for(int i = 0; i < B; i++) {
            for(int mask = 0; mask < (1 << B); mask++) {
                if((mask & (1 << i)) != 0) {
                    f[mask] += f[mask ^ (1 << i)];///you can change the operator from + to min/gcd to find min/gcd of all f[submasks]
                }
            }
        }
        return f;
    }

    ///mu(f(s))=\sum_{s' $ s}{(-1)^|s\s'| * f(s')}
    ///O(B * 2 ^ B)
    vector<int> mobius_transform(vector<int> f)
    {
        for(int i = 0; i < B; i++) {
            for(int mask = 0; mask < (1 << B); mask++) {
                if((mask & (1 << i)) != 0) {
                    f[mask] -= f[mask ^ (1 << i)];
                }
            }
        }
        return f;
    }

    vector<int> inverse_zeta_transform(vector<int> f)
    {
        return mobius_transform(f);
    }

    vector<int> inverse_mobius_transform(vector<int> f)
    {
        return zeta_transform(f);
    }

    /// z(f(s))=\sum_{s' is supermask of s}{f(s')}
    ///O(B * 2 ^ B)
    ///zeta transform is actually SOS DP
    vector<int> zeta_transform_for_supermasks(vector<int> f)
    {
        for(int i = 0; i < B; i++) {
            for(int mask=(1<<B)-1 ; mask>=0 ; mask--){
                if((mask&(1<<i)) == 0) f[mask] += f[mask^(1<<i)] ;
            }
        }
        return f;
    }

    ///f*g(s)=sum_{s' $ s} {f(s')*g(s\s')}
    ///O(B * B * 2 ^ B)
    vector<int> subset_sum_convolution(vector<int> f, vector<int> g)
    {
        vector< vector<int> > fhat(B+1, vector<int> (1<<B, 0));
        vector< vector<int> > ghat(B+1, vector<int> (1<<B, 0));
        // Make fhat[][] = {0} and ghat[][] = {0}
        for(int mask = 0; mask < (1 << B); mask++) {
            fhat[__builtin_popcount(mask)][mask] = f[mask];
            ghat[__builtin_popcount(mask)][mask] = g[mask];
        }
        // Apply zeta transform on fhat[][] and ghat[][]
        for(int i = 0; i <= B; i++) {
            for(int j = 0; j <= B; j++) {
                for(int mask = 0; mask < (1 << B); mask++) {
                    if((mask & (1 << j)) != 0) {
                        (fhat[i][mask] += fhat[i][mask ^ (1 << j)])%=mod;
                        (ghat[i][mask] += ghat[i][mask ^ (1 << j)])%=mod;
                    }
                }
            }
        }
        vector< vector<int> > h(B+1, vector<int> (1<<B, 0));
        // Do the convolution and store into h[][] = {0}
        for(int mask = 0; mask < (1 << B); mask++) {
            for(int i = 0; i <= B; i++) {
                for(int j = 0; j <= i; j++) {
                    h[i][mask] += 1LL*fhat[j][mask] * ghat[i - j][mask]%mod;
                    h[i][mask]%=mod;
                }
            }
        }

        // Apply inverse SOS dp on h[][]
        for(int i = 0; i <= B; i++) {
            for(int j = 0; j <= B; j++) {
                for(int mask = 0; mask < (1 << B); mask++) {
                    if((mask & (1 << j)) != 0) {
                        h[i][mask] -= h[i][mask ^ (1 << j)];
                        (h[i][mask]+=mod)%=mod;
                    }
                }
            }
        }
        vector<int> fog(1<<B, 0);
        for(int mask = 0; mask < (1 << B); mask++)  fog[mask] = h[__builtin_popcount(mask)][mask];
        return fog;
    }
}sos;
int a[N], b[N], cnt[N], f[N];
int32_t main()
{
    int n=in();
    for(int i=1; i<=n; i++) {int k=in(); cnt[k]++, b[k]++;}
    vector<int> va(cnt, cnt+N);
    auto conv=sos.subset_sum_convolution(va, va);
    for(int i=0; i<N; i++) a[i]=conv[i];
    vector<int> c=t.convolution(N, cnt, cnt, XOR);
    f[0]=0,f[1]=1;
    for(int i=2; i<N; i++) f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=0; i<N; i++){
        a[i]=1LL*a[i]*f[i]%mod;
        b[i]=1LL*b[i]*f[i]%mod;
        c[i]=1LL*c[i]*f[i]%mod;
    }
    vector<int> an=t.convolution(N, a, b, AND);
    vector<int> ans=t.convolution(N, an.data(), c.data(), AND);
    int res=0;
    for(int i=0; i<17; i++) res=(res+ans[1<<i])%mod;
    cout<<res<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
