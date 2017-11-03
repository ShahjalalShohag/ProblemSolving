#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,ans=0;
    string s;
    char ch='a';
    cin>>s;
    for(i=0;i<s.length();i++){
        if(abs(s[i]-ch)>26-abs(s[i]-ch)) ans+=26-abs(s[i]-ch);
        else ans+=abs(s[i]-ch);
        ch=s[i];
    }
    cout<<ans<<endl;
    return 0;
}
