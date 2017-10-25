#include<bits/stdc++.h>
using namespace std;
int main()
{

  int n,i,k,ans=0;
  string a,b;
  cin>>n;
  cin>>a>>b;
  for(i=0;i<n;i++){
        k=abs(b[i]-a[i]);
    k>10-k?ans+=10-k:ans+=k;
  }
  cout<<ans<<endl;
  return 0;
}
