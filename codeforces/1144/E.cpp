#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?'\n':' ')
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fbo find_by_order
#define ook order_of_key
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define SQ(x) ((x)*(x))
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define sz(v) (int)v.size()
#define pf printf
#define sf scanf
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%I64d %I64d\n",a,b)
#define pf3ll(a,b,c)          printf("%I64d %I64d %I64d\n",a,b,c)
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
inline void yes(){cout<<"YES\n";exit(0);}
inline void no(){cout<<"NO\n";exit(0);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 rnd(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


// base and base_digits must be consistent
constexpr ll base = 26*26*26*26;
constexpr ll base_digits = 4;
struct bigint {
    vll a; ll sign;

    bigint() : sign(1) {}

    bigint(ll v) {*this = v;}

    bigint(const string &s) {read(s);}

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(ll v) {
        sign = 1;
        if (v < 0) sign = -1, v = -v;
        a.clear();
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;
            for (ll i = 0, carry = 0; i < (ll)max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (ll)res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (ll)a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (ll i = 0, carry = 0; i < (ll)v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (ll)v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry) res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(ll v) {
        if (v < 0) sign = -sign, v = -v;
        for (ll i = 0, carry = 0; i < (ll)a.size() || carry; ++i) {
            if (i == (ll)a.size()) a.push_back(0);
            ll cur = a[i] * v + carry;
            carry = cur / base;
            a[i] = cur % base;
        }
        trim();
    }

    bigint operator*(ll v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        ll norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());
        for (ll i = (ll)a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            ll s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            ll s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            ll d = (base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(ll v) {
        if (v < 0) sign = -sign, v = -v;
        for (ll i = (ll)a.size() - 1, rem = 0; i >= 0; --i) {
            ll cur = a[i] + rem * base;
            a[i] = cur / v;
            rem = cur % v;
        }
        trim();
    }

    bigint operator/(ll v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    ll operator%(ll v) const {
        if (v < 0) v = -v;
        ll m = 0;
        for (ll i = (ll)a.size() - 1; i >= 0; --i)
            m = (a[i] + m * base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign) return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (ll i = (ll)a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back()) a.pop_back();
        if (a.empty()) sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && a[0] == 0);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    ll longValue() const {
        ll res = 0;
        for (ll i = (ll)a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        ll pos = 0;
        while (pos < (ll)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -sign;
            ++pos;
        }
        for (ll i = (ll)s.size() - 1; i >= pos; i -= base_digits) {
            ll x = 0;
            for (ll j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 26 + s[j] - 'a';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1) stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (ll i = (ll)v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('a') << v.a[i];
        return stream;
    }

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        ll n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (ll i = 0; i < n; i++)
                for (ll j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
        ll k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());
        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);
        for (ll i = 0; i < k; i++) a2[i] += a1[i];
        for (ll i = 0; i < k; i++) b2[i] += b1[i];
        vll r = karatsubaMultiply(a2, b2);
        for (ll i = 0; i < (ll)a1b1.size(); i++) r[i] -= a1b1[i];
        for (ll i = 0; i < (ll)a2b2.size(); i++) r[i] -= a2b2[i];
        for (ll i = 0; i < (ll)r.size(); i++) res[i + k] += r[i];
        for (ll i = 0; i < (ll)a1b1.size(); i++) res[i] += a1b1[i];
        for (ll i = 0; i < (ll)a2b2.size(); i++) res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vll a(this->a.begin(), this->a.end());
        vll b(v.a.begin(), v.a.end());
        while (a.size() < b.size()) a.push_back(0);
        while (b.size() < a.size()) b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (ll i = 0, carry = 0; i < (ll)c.size(); i++) {
            ll cur = c[i] + carry;
            res.a.push_back(cur % base);
            carry = cur / base;
        }
        res.trim();
        return res;
    }
};

string getRes(ll k, bigint& c) {
    string res;
    for (ll x : c.a) {
        for (ll i = 0; i < 4; i++) {
            res.push_back((char)((x % 26) + 'a'));
            x /= 26;
        }
    }
    while (sz(res) > k) res.pop_back();
    while (sz(res) < k) res.push_back('a');
    reverse(all(res));
    return res;
}

int main() {
    BeatMeScanf;
    ll k;
    bigint a, b;
    cin >> k >> a >> b;
    bigint c = (a + b) / 2;
    cout << getRes(k, c) << endl;
}
