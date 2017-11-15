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
#define mapii map<int,int>
#define si set<int>
#define umapii unordered_map<int,int>
#define len(s) s.length()
#define vit vector<int>::iterator
#define szfr(a,b,c) for(a=b;a<c.size();a++)
#define mapit mapii::iterator
#define umapit umapii::iterator
#define sit si::iteartor
#define vs vector<string>
#define mpsi map<string,int>
#define popf pop_front
#define popb pop_back
#define pf push_front
#define di deque<int>
int main()
{
    int n,i,j,k,f,m,s,ans=0;
    di a,b;
    cin>>n;
    cin>>f;
    fr(i,0,f){
        cin>>k;
        a.pb(k);
    }
    cin>>s;
    fr(i,0,s){
        cin>>k;
        b.pb(k);
    }
    eqfr(m,1,1000){
        if(a.empty()){
            cout<<ans<<" "<<2<<endl;
            return 0;
        }
        if(b.empty()){
            cout<<ans<<" "<<1<<endl;
            return 0;
        }
        if(a[0]>b[0]){
                a.pb(b[0]);
                b.popf();
                a.pb(a[0]);
                a.popf();
        }
        else{
            b.pb(a[0]);
            a.popf();
            b.pb(b[0]);
            b.popf();
        }
        ans++;
    }
    cout<<-1<<endl;
    return 0;
}
