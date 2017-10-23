#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,f,flag=1;
    string a,b,s;
    cin>>a>>b>>s;
    for(i=0;i<a.length();i++){
        f=s.find(a[i]);
        if(f!=string::npos) s.erase(s.begin()+f);
        else flag=0;
    }
    for(i=0;i<b.length();i++){
        f=s.find(b[i]);
        if(f!=string::npos) s.erase(s.begin()+f);
        else flag=0;
    }
    if(flag==1&&s.size()==0) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

