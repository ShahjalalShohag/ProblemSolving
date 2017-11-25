#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define vpii vector<pair<int,int>>
#define si set<int>
#define usi unordered_set<int>
#define ss set<string>
#define spii set<pair<int,int>>
#define di deque<int>
#define li list<int>
#define sti stack<int>
#define qi queue<int>
#define pq priority_queue<int>
#define mii map<int,int>
#define mll map<ll,ll>
#define umii unordered_map<int,int>
#define vit vector<int>::iterator
#define mit map<int,int>::iterator
#define sit set<int>:: iterator

#define fr(i,a,b) for(int i=a;i<b;i++)
#define rfr(i,a,b) for(int i=b-1;i>=a;i--)
#define eqfr(i,a,b) for(int i=a;i<=b;i++)
#define reqfr(i,a,b) for(int i=b;i>=a;i--)
#define printa(a,L,R) fr(i,L,R)cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define pb push_back
#define pf push_front
#define popb pop_front
#define popf pop_front
#define mp make_pair
#define fi first
#define se second
#define fill(a,x) memset(a,x,sizeof(a))
#define fill2d(a,x,n,m) memset(a,x,n*m*sizeof(a[0][0]))
#define inf 0x3f3f3f3f
#define mod 1e9+7
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))

#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) cout(v.begin(),v.end(),a)
#define len(s) s.length()
#define strtoint(a) atoi(a.c_str())
string inttostr(int n){stringstream rr;rr<<n;return rr.str();}

#define fast ios_base::sync_with_stdio(false)
string s;
bool check()
{
    for(int i=2;i<s.length();i++) if(s[i]=='C') return true;
    return false;
}
void exceltonormal(string k,int row)
{
    int col=0;
    for(int i=0;i<k.length();i++){
        col=col*26+s[i]-'A'+1;
    }
    string ans="R"+inttostr(row)+"C"+inttostr(col);
    cout<<ans<<nl;
}
void normaltoexcel(int row,int col)
{
    string ans;
    while(col>0){
        int r=(col-1)%26;
        ans+=(char)('A'+r);
        col=(col-1)/26;
    }
    rev(ans);
    cout<<ans<<row<<nl;
}
int main()
{
    fast;
    int n,i,j;
    string tmp,tmp2;
    cin>>n;
    while(n--){
        cin>>s;
        if(s[0]=='R'&&s[1]<='9'&&check()){
            tmp="",tmp2="";
            i=1;
            while(s[i]!='C') {tmp+=(char)s[i];i++;}
            i++;
            while(s[i]) {tmp2+=(char)s[i];i++;}
            int p=strtoint(tmp);
            int q=strtoint(tmp2);
            normaltoexcel(p,q);
        }
        else{
            tmp="",tmp2="";
            i=0;
            while(s[i]>'9') {tmp+=(char)s[i];i++;}
            while(s[i]) {tmp2+=(char)s[i];i++;}
            int m=strtoint(tmp2);
            exceltonormal(tmp,m);
        }
    }
    return 0;
}

