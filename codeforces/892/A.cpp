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
int main()
{
    ll n,i,j,a,sum=0,b[100100];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        sum+=a;
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b,b+n);
    if(b[n-1]+b[n-2]>=sum) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
