#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,n,k,i,c=1,m;
    cin>>n>>m;
    a=n;
    k=n;
    i=1;
    while(c>0){
            c=0;
        for(;i<=k;i++) if(i%m==0) c++;
        i=k+1;
        a+=c;
        k=a;
    }
    cout<<a<<endl;
    return 0;
}
