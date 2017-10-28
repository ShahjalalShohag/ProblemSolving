#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    string s,a="",b="",c;
    cin>>s>>n;
    for(i=0;i<n;i++){
        cin>>c;
        if(c==s){
            cout<<"YES\n";
            return 0;
        }
        a+=c[1];
        b+=c[0];
    }
    size_t fnd=a.find(s[0]);
    size_t found=b.find(s[1]);
    if(fnd!=string::npos&&found!=string::npos) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
