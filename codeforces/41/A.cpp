#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s,t;
    cin>>s>>t;
    reverse(s.begin(),s.end());
    if(s==t) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
