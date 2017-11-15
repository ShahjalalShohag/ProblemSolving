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
int main()
{
    int n,i,j,ans;
    cin>>n;
    if(n&1) ans=(n*n+1)/2;
    else ans=n*n/2;
    cout<<ans<<endl;
    eqfr(i,1,n){
        eqfr(j,1,n){
            if(((i&1)&&(j&1))||(!(i&1)&&!(j&1))) cout<<'C';
            else cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}
