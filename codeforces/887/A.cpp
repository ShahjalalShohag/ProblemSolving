#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,pos,cnt=0;
    string s;
    cin>>s;
    pos=s.find('1');

    if(pos==string::npos){
        cout<<"no\n";
        return 0;
    }
    for(i=pos+1;i<s.length();i++){
        if(s[i]=='0') cnt++;
    }
    if(cnt>=6) cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}
