#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    char  s[100100],*p;
    cin>>s;
    if((p=strstr(s,"AB")) && strstr(p+2,"BA")) cout<<"YES\n";
    else if((p=strstr(s,"BA")) && strstr(p+2,"AB")) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
