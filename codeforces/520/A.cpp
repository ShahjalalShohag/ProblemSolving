#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,k,n,a[200]={0};
    string s;
    cin>>n>>s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(i=0;i<n;i++) a[int(s[i])]=1;
    k=count(a+97,a+123,1);
    if(k<26) cout<<"NO\n";
    else cout<<"YES\n";
    return 0;
}

