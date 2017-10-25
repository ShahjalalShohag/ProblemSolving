#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,m;
    cin>>n>>k;
    m=480-2*k;
    for(i=1;i<=n;i++){
        if(i*(i+1)>m/5) break;
    }
    cout<<i-1<<endl;
    return 0;
}
