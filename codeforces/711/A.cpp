#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,k,flag=0;
    string s;
    cin>>n;
    vector<string>v(n);
    for(i=0;i<n;i++){
        cin>>s;
        k=s.find("OO");
        if(k!=string::npos&&flag==0) {
                s.replace(k,2,"++");
        flag=1;
        v[i]=s;
        }
        else v[i]=s;
    }
    if(flag==0) cout<<"NO\n";
    else{
            cout<<"YES\n";
        for(i=0;i<n;i++) cout<<v[i]<<endl;
    }
    return 0;
}
