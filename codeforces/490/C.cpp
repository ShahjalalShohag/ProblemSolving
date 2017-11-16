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
#define qi queue<int>
#define itfr(a,b) for(a=b.begin(),a!=b.end(),a++)
#define fill(a,x) memset(a,0,sizeof(a))
#define mpii map<int,int>
#define si set<int>
#define umpii unordered_map<int,int>
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
int main()
{
    ll  n,i,j,tmp,a,b,len,ans,x=-1,rtol=0,toright[1001000],toleft[1001000];
    string s;
    cin>>s>>a>>b;
    len=s.length();
    toright[0]=(s[0]-'0')%a;
    fr(i,1,len) toright[i]=(toright[i-1]*10+s[i]-'0')%a;
    toleft[0]=1;
    fr(i,1,len) toleft[i]=(toleft[i-1]*10)%b;
    for(i=len-1;i>0;i--){
        rtol=(rtol+(s[i]-'0')*toleft[len-i-1])%b;
        if(s[i]!='0'&&rtol==0&&toright[i-1]==0){
            x=i;
            break;
        }
    }
    if(x==-1) cout<<"NO\n";
    else{
        cout<<"YES\n";
        fr(i,0,x) cout<<s[i];
        cout<<endl;
        fr(i,x,len) cout<<s[i];
        cout<<endl;
    }
    return 0;
}
