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

/*
# series link will lead from the vertex v to the vertex u corresponding
  to the maximum suffix palindrome of v which satisfies diff(v) != diff(u)
# path within series links to the root contains only O(log n) vertices
# let us consider a suffix palindrome v s.t. link(v) != slink(v).
  Then, the previous occurrence of link(v) in the string was in position i - diff(v)
*/
int ans[N], series_ans[N];
struct PalindromicTree
{
    struct node
    {
        int nxt[26], len, st, en, suflink, diff, slink;
        int cnt;            //number of palindromic suffixes of this node
        int oc;             //stores the number of occurrences of the node
    };
    string s;
    vector<node> t;
    int sz, suf;
    void init(int len)
    {
        t.clear(); t.resize(len + 9);
        sz = 2, suf = 2;
        t[1].len = -1, t[1].suflink = 1;
        t[2].len = 0, t[2].suflink = 1;
        t[1].diff = t[2].diff = 0;
        t[1].slink = 1; t[2].slink = 2;
    }
    // returns 1 if it creates a new palindrome
    int add_letter(int pos)
    {
        int cur = suf, curlen = 0;
        int ch = s[pos] - 'a';
        while(1){
            curlen = t[cur].len;
            if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) break;
            cur = t[cur].suflink;
        }
        if(t[cur].nxt[ch]){
            suf = t[cur].nxt[ch];
            t[suf].oc++;
            return 0;
        }
        sz++; suf = sz;
        t[sz].oc = 1;
        t[sz].len = t[cur].len + 2;
        t[cur].nxt[ch] = sz;
        t[sz].en = pos;
        t[sz].st = pos-t[sz].len+1;
        if(t[sz].len == 1){
            t[sz].suflink = 2;
            t[sz].cnt = 1;
            t[sz].diff = 1;
            t[sz].slink = 2;
            return 1;
        }
        while(1){
            cur = t[cur].suflink;
            curlen = t[cur].len;
            if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]){
                    t[sz].suflink = t[cur].nxt[ch];
                    break;
            }
        }
        t[sz].cnt = 1 + t[t[sz].suflink].cnt;
        t[sz].diff = t[sz].len - t[t[sz].suflink].len;
        if(t[sz].diff == t[t[sz].suflink].diff) t[sz].slink = t[t[sz].suflink].slink;
        else t[sz].slink = t[sz].suflink;
        return 1;
    }
    int build(string &p)
    {
        s = p;
        int n = p.size();
        int tot = 0;
        for(int i = 0; i < n; i++) tot += add_letter(i);
        return tot;
    }
    void calc_oc()
    {
        for(int i = sz;i >= 3; i--) t[t[i].suflink].oc += t[i].oc;
    }
    void calc_dp(int i) //call it after adding each letter s[i], i = 1 indexed
    {
        for(int v = suf; t[v].len > 0; v = t[v].slink)
        {
            series_ans[v] = ans[i - (t[t[v].slink].len + t[v].diff)];
            if(t[v].diff == t[t[v].suflink].diff) series_ans[v] = (series_ans[v] + series_ans[t[v].suflink]) % mod;
            if(i % 2 == 0) ans[i] = (ans[i] + series_ans[v]) % mod;
        }
    }
}t;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string p; cin >> p;
    string s = "";
    int n = p.size();
    for(int i = 0, j = n - 1; i <= j; i++, j--) s += p[i], s += p[j];
    t.init(n); t.s = s;
    ans[0] = 1;
    for(int i = 0; i < n; i++){
        t.add_letter(i);
        t.calc_dp(i + 1);
    }
    cout << ans[n] << nl;
    return 0;
}

