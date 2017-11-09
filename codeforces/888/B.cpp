#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,l,u,d,r,ans1=0,ans2=0;
    string s;
    cin>>n>>s;
    l=d=u=r=0;
    for(i=0;i<s.length();i++){
        if(s[i]=='L') l++;
        else if(s[i]=='U') u++;
        else if(s[i]=='R') r++;
        else if(s[i]=='D')d++;
    }
    ans1=2*min(l,r);
    ans2=2*min(u,d);
    cout<<ans1+ans2<<endl;
}

