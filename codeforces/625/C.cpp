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
  int n,i,j,sum,k,m,a[501][501];
  cin>>n>>k;
  m=1;
  for(i=0;i<n;i++){
    fr(j,0,k-1) a[i][j]=m++;
  }
  for(i=0;i<n;i++){
    fr(j,k-1,n) a[i][j]=m++;
  }
  sum=0;
  fr(i,0,n) sum+=a[i][k-1];
  cout<<sum<<endl;
  for(i=0;i<n;i++){
    fr(j,0,n) cout<<a[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
