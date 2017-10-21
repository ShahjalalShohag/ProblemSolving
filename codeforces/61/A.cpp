#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,i,j;
    string a,b;
    cin>>a>>b;
    for(i=0;i<a.length();i++){
        if(a[i]==b[i]) cout<<0;
        else cout<<1;
    }
    cout<<endl;
    return 0;
}
