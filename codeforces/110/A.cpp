#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n=0,i;
    string s;
    cin>>s;
    for(i=0;i<s.length();i++){
        if(s[i]=='4'||s[i]=='7') n++;
    }
    if(n==4||n==7)  cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
