#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,c=0;
  string s;
  cin>>n;
  cin>>s;
  for(int i=0;i<s.length();i++){
    if(s[i]=='1') c++;
  }
  cout<<abs(n-2*c)<<endl;
  return 0;
}
