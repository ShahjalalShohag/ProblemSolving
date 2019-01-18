#include <bits/stdc++.h>
using namespace std;

#define fastio          std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define LL              long long
#define LD              long double
//#define MAX             200005
//#define MOD             1000000007
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)
#define SET(a, b)       memset(a, b, sizeof(a))
#define pb              push_back
#define mp              make_pair
#define fi              first
#define sec             second
#define aLL(c)          (c).begin(),(c).end()
#define aLLr(c)         (c).rbegin(),(c).rend()
#define loop(c,i)       for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(aLL(c),x) != (c).end())
#define BLOCK 555   // Optimum in Most Cases    Mo's Algo see Anudeep Bookamrks

long mul(long a, long b, long c){long long res=(long long)a*b;return(res>=c?res%c:res);}

template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
//(a - b) % c
template<typename T> T mod_neg(T a, T b) {a=mod(a, b);if(a<0){a+=b;}return a;}
//(a * b) % c for very large numbers, to avoid overflows
//O(1) hack taken from http://codeforces.com/blog/entry/15884
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((LD)a*(LD)b)/(LD)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
//(a ^ n)
//Complexity: O(log (n))
template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
//(a ^ n) % m
//Complexity : O(log (n))

template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T>T powerL(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}

template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
//gcd of 2 numbers a, b
//Complexity: O(log(max(a, b)))
template<typename T> T gcd(T a, T b) { return (b ? __gcd(a,b) : a); }
//lcm of 2 numbers a and b
//Complexity: O(log(max(a, b)))
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template<typename T> T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}
template<class T> T fast_gcd(T u, T v) {
    long shl = 0; while ( u && v && u != v) { T eu = u & 1; u >>= eu ^ 1; T ev = v & 1; v >>= ev ^ 1;
        shl += (~(eu | ev) & 1); T d = u & v & 1 ? (u + v) >> 1 : 0; T dif = (u - v) >> (sizeof(T) * 8 - 1); u -= d & ~dif; v -= d & dif;
    } return std::max(u, v) << shl;
}
// Most immportant one best optimised
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// tree defined...
using namespace __gnu_pbds;
typedef tree <long, null_type, less<long>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
//All indexing is 0-based
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar.

LL n,m,k,a[5005];
LL dp[5005][5005];

LL go(LL idx, LL k){

        if(k == 0)  return 0;
        if(idx == n+1) return -1e15;
        LL &ans = dp[idx][k];
        if(ans != -1)   return ans;

        LL t1=0 ;
        if(idx+m<=n+1) t1=a[idx+m-1]-a[idx-1]+go(idx+m,k-1);
        LL t2 = go(idx+1,k);
        //v.push_back(max(t1,t2));
        return ans = max(t1,t2);
}


int main(){

    cin>>n>>m>>k;
    MYREP(i,1,n){
        cin>>a[i],a[i] += a[i-1];
    }
    memset(dp,-1,sizeof dp);
    cout<<go(1,k)<<"\n";

    //sort(aLL(v));
    /*
    REP(i,v.size()){
        cout<<v[i]<<" ";
    }*/

}
