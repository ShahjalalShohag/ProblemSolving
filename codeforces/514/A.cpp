#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    string s;
    cin>>s;
    int l=s.length();
    for(i=0;i<l;i++){
        s[i]=s[i]-'0';
        if((i!=0&&9-s[i]<s[i])||(i==0&&s[i]!=9&&9-s[i]<s[i])) cout<<9-s[i];
        else cout<<s[i]-0;
    }
    cout<<endl;
    return 0;
}
