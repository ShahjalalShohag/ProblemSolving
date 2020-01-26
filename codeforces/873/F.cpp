#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 4e5 + 9;
const int mod = 1e9 + 7;

struct SuffixAutomaton{
    struct node {
        int len, link, firstpos, is_clone;
        map<char, int> nxt;
    };
    int sz, last;
    vector<node> t;
    vector<int> terminal;
    vector<ll> dp;
    SuffixAutomaton(){}
    void init(int n)
    {
        t.clear();
        terminal.clear();
        dp.clear();
        t.resize(2*n);
        terminal.resize(2*n);
        dp.resize(2*n, -1);
        sz = 1; last = 0;
        t[0].len = 0;
        t[0].link = -1;
        t[0].firstpos = 0;
        t[0].is_clone = 0;
    }
    void extend(char c)
    {
        int cur = sz++;
        t[cur].len = t[last].len + 1;
        t[cur].firstpos = t[cur].len;
        t[cur].is_clone = 0;
        int p = last;
        while(p != -1 && !t[p].nxt.count(c)){
            t[p].nxt[c] = cur;
            p = t[p].link;
        }
        if(p == -1) t[cur].link = 0;
        else{
            int q = t[p].nxt[c];
            if(t[p].len + 1 == t[q].len) t[cur].link = q;
            else{
                int clone = sz++;
                t[clone].len = t[p].len+1;
                t[clone].nxt = t[q].nxt;
                t[clone].link = t[q].link;
                t[clone].firstpos = t[q].firstpos;
                t[clone].is_clone = 1;
                while(p != -1 && t[p].nxt[c] == q){
                    t[p].nxt[c] = clone;
                    p = t[p].link;
                }
                t[q].link = t[cur].link = clone;
            }
        }
        last = cur;
    }
    void get_terminals()
    {
        int p = last;
        while(p > 0) terminal[p] = 1, p = t[p].link;
    }
    void build(string &s)
    {
        for (auto x: s) extend(x);
        get_terminals();
    }
    ll cnt(int i)
    {
        if(dp[i]!=-1) return dp[i];
        ll ret = terminal[i];
        for(auto x: t[i].nxt) ret += cnt(x.second);
        return dp[i] = ret;
    }
}sa;

int cnt[N];
string s, p;
vector<int> g[N];
void dfs(int u)
{
    if(sa.t[u].is_clone == 0) cnt[u] = p[sa.t[u].firstpos-1] == '0';
    for(auto v: g[u]){
        dfs(v);
        cnt[u] += cnt[v];
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cin >> s >> p;
    sa.init(n); sa.build(s);
    for(int i = 1; i < sa.sz; i++) g[sa.t[i].link].eb(i);
    dfs(0);
    ll ans = 0;
    for(int i = 1; i < sa.sz; i++) ans = max(ans, 1LL * sa.t[i].len * cnt[i]);
    cout << ans << nl;
    return 0;
}
