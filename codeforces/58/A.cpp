#include<bits/stdc++.h>
using namespace std;
int main()
{

    int i,j=0;
    string s;
    cin>>s;
    string k("hello");
    for(i=0;i<s.length();i++){
        if(s[i]==k[j]) j++;
        if(j==5){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}
