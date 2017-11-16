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
#define mp make_pair
int sum(string s)
{
    int i,ans=0;
    fr(i,0,s.length()) ans+=s[i]-'0';
    return ans;
}
int main()
{
    int n,i,j,ans,cnt=0;
    string s;
    cin>>s;
    while(s.length()>1){
        cnt++;
        ans=sum(s);
        stringstream k;
        k<<ans;
        s=k.str();
    }
    cout<<cnt<<endl;
    return 0;
}
