//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MP make_pair
#define fs first
#define sc second
#define F first
#define S second
#define nl "\n"
#define asche cerr<<"Ekhane asche\n";
#define pf printf
#define sf scanf
#define mem(a,x) memset(a,x,sizeof(a))
#define SZ(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define one(x) __builtin_popcount(x)
#define fout(x) fixed<<setprecision(x)
#define BeatMeScanf ios_base::sync_with_stdio(false)
//int dx[]={1,0,-1,0,1,-1,-1,1};
//int dy[]={0,1,0,-1,1,1,-1,-1};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}
//template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
namespace IO
{
    #define in() ( { int a ; scanf("%d",&a); a; } )
    #define LL() ( { ll a ; scanf("%I64d",&a); a; } )
    #define ULL() ( { ull a ; scanf("%llu",&a); a; } )
    #define DD() ({ double a; scanf("%lf", &a); a;})
    #define CC() ( { char a ; scanf("%c",&a); a; } )
    #define pf1(a) printf("%d\n",a)
    #define pf1ll(a) printf("%lld\n",a)
}
using namespace IO;

const int mod=1e9+7;
const int N=1e6+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

namespace NT{
    template<typename T>
    struct bigger_type{};
    template<typename T> using bigger_type_t = typename bigger_type<T>::type;
    template<> struct bigger_type<int>{using type = long long;};
    template<> struct bigger_type<unsigned int>{using type = unsigned long long;};
    //template<> struct bigger_type<int64_t>{using type = __int128;};
    //template<> struct bigger_type<uint64_t>{using type = unsigned __int128;};

    template<typename int_t = unsigned long long>
    struct Mod_Int{
        static inline int_t add(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = a+b;
            if(ret>=mod) ret-=mod;
            return ret;
        }
        static inline int_t sub(int_t const&a, int_t const&b, int_t const&mod){
            return add(a, mod-b);
        }
        static inline int_t mul(int_t const&a, int_t const&b, int_t const&mod){
            uint64_t ret = a * (uint64_t)b - (uint64_t)((long double)a * b / mod - 1.1) * mod;
			if(-ret < ret){
				ret = mod-1-(-ret-1)%mod;
			} else {
				ret%=mod;
			}

			//ret = min(ret, ret+mod);
			int64_t out = ret;
			/*if(out != a*(__int128) b % mod){
				cerr << (long double)a * b / mod << " " << (uint64_t)((long double)a * b / mod - 0.1) << "\n";
				cerr << mod << " " << ret << " " << ret+mod << " " << out << " " << (int64_t)(a*(__int128) b % mod) << "\n";
				assert(0);
			}*/
			return out;
            //return a*static_cast<bigger_type_t<int_t>>(b)%mod;
        }
        static inline int_t pow(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = 1;
            int_t base = a;
            for(int i=0;b>>i;++i){
                if((b>>i)&1) ret = mul(ret, base, mod);
                base = mul(base, base, mod);
            }
            return ret;
        }
    };

    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type is_prime(T x){
        if(x<T(4)) return x>T(1);
        for(T i=2;i*i<=x;++i){
            if(x%i == 0) return false;
        }
        return true;
    }

    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_single(T const&x, T base){
        if(x<T(4)) return x>T(1);
        if(x%2 == 0) return false;
        base%=x;
        if(base == 0) return true;

        T xm1 = x-1;
        int j = 1;
        T d = xm1/2;
        while(d%2 == 0){ // could use __builtin_ctz
            d/=2;
            ++j;
        }
        T t = Mod_Int<T>::pow(base, d, x);
        if(t==T(1) || t==T(xm1)) return true;
        for(int k=1;k<j;++k){
            t = Mod_Int<T>::mul(t, t, x);
            if(t == xm1) return true;
            if(t<=1) break;
        }
        return false;
    }

    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const&){return true;}
    template<typename T, typename... S>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const&x, T const&base, S const&...bases){
        if(!miller_rabin_single(x, base)) return false;
        return miller_rabin_multi(x, bases...);
    }

    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin(T const&x){
        if(x < 316349281) return miller_rabin_multi(x, T(11000544), T(31481107));
        if(x < 4759123141ull) return miller_rabin_multi(x, T(2), T(7), T(61));
        return miller_rabin_multi(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
    }

    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type isqrt(T const&x){
        assert(x>=T(0));
        T ret = static_cast<T>(sqrtl(x));
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type icbrt(T const&x){
        assert(x>=T(0));
        T ret = static_cast<T>(cbrt(x));
        while(ret>0 && ret*ret*ret>x) --ret;
        while(x-ret*ret*ret>3*ret*(ret+1))
            ++ret;
        return ret;
    }
    /*uint64_t isqrt(unsigned __int128 const&x){
        unsigned __int128 ret = sqrtl(x);
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }*/
    vector<uint16_t> saved;
    // fast prime factorization from
    // https://github.com/radii/msieve
    uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div){
        if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
        //cerr << "try: " << x << " " << k << "\n";
        saved.clear();
        uint64_t scaledn = k*x;
        if(scaledn>>62) return 1;
        uint32_t sqrtn = isqrt(scaledn);
        uint32_t cutoff = isqrt(2*sqrtn)/cutoff_div;
        uint32_t q0 = 1;
        uint32_t p1 = sqrtn;
        uint32_t q1 = scaledn-p1*p1;

        if(q1 == 0){
            uint64_t factor = __gcd(x, (uint64_t)p1);
            return factor==x ? 1:factor;
        }

        uint32_t multiplier = 2*k;
        uint32_t coarse_cutoff = cutoff * multiplier;
        //cerr << "at: " << multiplier << "\n";

        uint32_t i, j;
        uint32_t p0 = 0;
        uint32_t sqrtq = 0;

        for(i=0;i<it_max;++i){
            uint32_t q, bits, tmp;

            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;

            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;

            if (q1 < coarse_cutoff) {
                tmp = q1 / __gcd(q1, multiplier);

                if (tmp < cutoff) {
                    saved.push_back((uint16_t)tmp);
                }
            }

            bits = 0;
            tmp = q0;
            while(!(tmp & 1)) {
                bits++;
                tmp >>= 1;
            }
            if (!(bits & 1) && ((tmp & 7) == 1)) {

                sqrtq = (uint32_t)isqrt(q0);

                if (sqrtq * sqrtq == q0) {
                    for(j=0;j<saved.size();++j){
                        if(saved[j] == sqrtq) break;
                    }
                    if(j == saved.size()) break;
                    //else cerr << "skip " << i << "\n";;
                }
            }
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;

            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;

            if (q0 < coarse_cutoff) {
                tmp = q0 / __gcd(q0, multiplier);

                if (tmp < cutoff) {
                    saved.push_back((uint16_t) tmp);
                }
            }
        }

        if(sqrtq == 1) { return 1;}
        if(i == it_max) { return 1;}

        q0 = sqrtq;
        p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;

        for(j=0;j<it_max;++j) {
            uint32_t q, tmp;

            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;

            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;

            if (p0 == p1) {
                q0 = q1;
                break;
            }

            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;

            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;

            if (p0 == p1)
                break;
        }
        if(j==it_max) {cerr << "RNG\n"; return 1;} // random fail

        uint64_t factor = __gcd((uint64_t)q0, x);
        if(factor == x) factor=1;
        return factor;
    }
    uint64_t squfof(uint64_t const&x){
//for using only squfof don't comment the following lines.
//for factorizing comment these, no problem.
//        for(uint64_t i=2;i<=min((int64_t)5000,(int64_t)x/2-1);i++){
//            uint64_t p=(uint64_t)((1.0*x)/(i*1.0)+eps);
//            if(p*i==x) return i;
//        }
        static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};

        uint64_t cbrt_x = icbrt(x);
        if(cbrt_x*cbrt_x*cbrt_x == x) return cbrt_x;

        //uint32_t iter_lim = isqrt(isqrt(x))+10;
        uint32_t iter_lim = 300;
        for(uint32_t iter_fact = 1;iter_fact<20000;iter_fact*=4){
            for(uint32_t const&k : multipliers){
                if(numeric_limits<uint64_t>::max()/k<=x) continue; //would overflow
                uint32_t const it_max = iter_fact*iter_lim;
                uint64_t factor = squfof_iter_better(x, k, it_max, 1);
                if(factor==1 || factor==x) continue;
                return factor;
            }
        }
        cerr << "failed to factor: " << x << "\n";
        assert(0);
        assert(0);
        return 1;
    }

    template<typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type factorize_brute(T x){
        vector<T> ret;
        while(x%2 == 0){
            x/=2;
            ret.push_back(2);
        }
        for(uint32_t i=3;i*(T)i <= x;i+=2){
            while(x%i == 0){
                x/=i;
                ret.push_back(i);
            }
        }
        if(x>1) ret.push_back(x);
        return ret;
    }

    template<typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type factorize(T x){
        //cerr << "factor: " << x << "\n";
        vector<T> ret;
        const uint32_t trial_limit = 5000;
		auto trial = [&](uint32_t const&i){
			while(x%i == 0){
                x/=i;
                ret.push_back(i);
            }
		};
		trial(2);
		trial(3);
        for(uint32_t i=5, j=2;i<trial_limit && i*i <= x;i+=j, j=6-j){
            trial(i);
        }
        if(x>1){
            static stack<T> s;
            s.push(x);
            while(!s.empty()){
                x = s.top(); s.pop();
                if(!miller_rabin(x)){
                    T factor = squfof(x);
                    if(factor == 1 || factor == x){assert(0); return ret;}
                    //cerr << x << " -> " << factor << "\n";
                    s.push(factor);
                    s.push(x/factor);
                } else {
                    ret.push_back(x);
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
}

ll a[N];
vpll vec;
vll di;
void gen(int i,ll nw)
{
    if(i==SZ(vec)){
        di.eb(nw);
        return;
    }
    gen(i+1,nw);
    for(int k=1;k<=vec[i].S;k++){
        nw*=vec[i].F;
        gen(i+1,nw);
    }
}
unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(ll x) const { return hash_f(x); }
};
gp_hash_table<ll, int, chash> id,mp;
int cnt[N];
int32_t main()
{
    ///BeatMeScanf;
    int n=in();
    for(int i=1;i<=n;i++) a[i]=LL();
    int it=10;
    ll ans=1;
    while(it--){
        int k=rnd()%n+1;
        //debug(k);
        //debug(a[k]);
        auto v=NT::factorize(a[k]);
        mp.clear();
        for(auto x:v) mp[x]++;
        vec.clear();
        for(auto x:mp) vec.eb(x.F,x.S);
        di.clear();
        gen(0,1);
        //debug(k,a[k]);
        //debug(SZ(di));

        sort(all(di));
        // debug(a[k]);
        //for(auto x:di) cout<<x<<' ';
        //cout<<nl;
        int d=SZ(di);
        id.clear();
        for(int i=0;i<d;i++) id[di[i]]=i;
        mem(cnt,0);
        for(int i=1;i<=n;i++) cnt[id[__gcd(a[i],a[k])]]++;
        for(auto x:vec){
            for(int i=d-1;i>=0;i--){
                if(di[i]%x.F==0){
                    cnt[id[di[i]/x.F]]+=cnt[i];
                    //assert(id[di[i]/x.F]<i);
                }
            }
        }
        for(int i=0;i<d;i++){
            if(2*cnt[i]>=n){
                ans=max(ans,di[i]);
            }
        }
    }
    pf1ll(ans);
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

