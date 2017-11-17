#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define inf 1<<28
#define pb push_back
#define fr(a,b,c) for(a=b;a<c;a++)
#define eqfr(a,b,c) for(a=b;a<=c;a++)
#define pii pair<int,int>
#define vi vector<int>
#define itfr(a,b) for(a=b.begin(),a!=b.end(),a++)
#define fill(a,x) memset(a,0,sizeof(a))
#define mpii map<int,int>
#define si set<int>
#define umpii unordered_map<int,int>
#define len(s) s.length()
#define vit vector<int>::iterator
#define szfr(a,b,c) for(a=b;a<c.size();a++)
#define mpit mapii::iterator
#define umpit umapii::iterator
#define sit si::iteartor
#define vs vector<string>
#define mpsi map<string,int>
#define popf pop_front
#define popb pop_back
#define pf push_front
#define di deque<int>
#define maxn 5000010
ll dp[maxn];
ll spf[maxn];
void solve()
{
    ll i,j;
    for(i=2;i<maxn;i++){
        if(spf[i]==0){
            for(j=1;j*i<maxn;j++) spf[j*i]=i;
        }
    }
    for(i=2;i<maxn;i++){
        dp[i]=1+dp[i/spf[i]];
    }
    for (i=2;i<maxn;i++){
        dp[i]+=dp[i-1];
    }

}
int main()
{
    int t,a,b;
    scanf("%d",&t);
    solve();
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%I64d\n",dp[a]-dp[b]);
    }
    return 0;
}
