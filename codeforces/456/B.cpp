#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,k;
    string s;
    cin>>s;
    k=s.length();
    if(k==1) n=s[k-1]-'0';
    else n=(s[k-2]-'0')*10+(s[k-1]-'0');
    if(n%4==0) cout<<4<<endl;
    else cout<<0<<endl;
    return 0;
}
