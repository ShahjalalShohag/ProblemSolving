#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[200]={0},i,k;
    string s;
    getline(cin,s);
    if(s=="{}"){
            cout<<0;
    return 0;
    }
    for(i=1;i<s.length()-1;i+=3){
        k=int(s[i]);
        a[k]=1;
    }
    i=count(a,a+200,1);
    cout<<i<<endl;
    return 0;
}
