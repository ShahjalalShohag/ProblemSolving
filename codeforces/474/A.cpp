#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,m;
    string s,k,a("qwertyuiopasdfghjkl;zxcvbnm,./");
    cin>>k>>s;
    if(k=="L"){
        for(i=0;i<s.length();i++){
            m=a.find(s[i]);
            cout<<a[m+1];
        }
    }
    else{
        for(i=0;i<s.length();i++){
            m=a.find(s[i]);
            cout<<a[m-1];
        }
    }
    cout<<endl;
    return 0;
}
