#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0,i,j,p,q;
    char ch;
    cin>>p>>q;
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            cin>>ch;
            if(ch=='C'||ch=='M'||ch=='Y') n=1;
        }
    }
    if(n==1) cout<<"#Color\n";
    else cout<<"#Black&White\n";
    return 0;
}
