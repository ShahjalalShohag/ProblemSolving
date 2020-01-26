#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 1e6 + 9;
const int mod = 1e9 + 7;

/**
len -> largest string length of the corresponding endpos-equivalent class
link -> longest suffix that is another endpos-equivalent class.
firstpos -> 1 indexed end position of the first occurrence of the largest string of that node
minlen(v) -> smallest string of node v = len(link(v)) + 1
terminal nodes -> store the suffixes
**/
bool vis[2*N];
struct SuffixAutomata{
    struct node {
        int len, link, firstpos;
        map<char, int> nxt;
    };
    int sz, last;
    vector<node> t;
    vector<int> terminal;
    vector<ll> dp;
    SuffixAutomata(){}
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
    }
    void extend(char c)
    {
        int cur = sz++;
        t[cur].len = t[last].len + 1;
        t[cur].firstpos = t[cur].len;
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
    string S;
    void build(string &s)
    {
        S=s;
        for (auto x: s) extend(x);
        get_terminals();
    }
    ll cnt(int i)///number of times i-th node occurs in the string
    {
        if(dp[i]!=-1) return dp[i];
        ll ret = terminal[i];
        for(auto x: t[i].nxt) ret += cnt(x.second);
        return dp[i] = ret;
    }
    ll solve(string &s)
    {
        int n = s.size();
        ll ans = 0;
        s += s;
        int cur = 0;
        vector<int> v;
        int len = 0;
        for(int i = 0; i < 2*n - 1; i++){
            while(cur != -1 && !t[cur].nxt.count(s[i])) cur = t[cur].link, len = t[cur].len;
            if(cur != -1) cur = t[cur].nxt[s[i]], len++;
            while(cur > 0 && n < t[ t[cur].link ].len + 1) cur = t[cur].link, len = t[cur].len;
            if(i >= n-1 && cur > 0 && len >= n && !vis[cur] ){
                ans += cnt(cur), vis[cur] = 1, v.eb(cur);
            }
        }
        for(auto x: v) vis[x] = 0;
        return ans;
    }
}sa;

int32_t main()
{
    char ch[N]; scanf("%s", ch); string s = ch;
    int n = s.size(); sa.init(n); sa.build(s);
    int q = in();
    while(q--){
        scanf("%s", ch); string p = ch;
        printf("%lld\n", sa.solve(p));
    }
    return 0;
}
