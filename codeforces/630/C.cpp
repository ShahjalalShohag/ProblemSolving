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
    int n,i,j;
    cin>>n;
int d[10010];

for( i=0;i<10010;i++)
   d[i]=0;

d[0]=1;

int carry=0;
int temp=0;
for( j=0;j<n+1;j++)
{
   carry=0;
   temp=0;
   for(i=0;i<10010;i++)
   {
      temp=d[i]*2+carry;
      d[i]= temp%10;
      carry = temp/10;
   }
}
for(i=10009;i>=0;i--) if(d[i]!=0) break;
for(;i>0;i--) cout<<d[i];
cout<<d[i]-2<<endl;
return 0;
}
