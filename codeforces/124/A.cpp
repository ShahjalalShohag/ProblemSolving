#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a,b,ans;
    cin>>n>>a>>b;
    if(n-a-1>b) cout<<b+1<<endl;
    else cout<<n-a<<endl;
    return 0;
}
