#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a,b,c,ans[6];
    cin>>a>>b>>c;
    ans[0]=a+b+c;
    ans[1]=a*b*c;
    ans[2]=a*b+c;
    ans[3]=a+b*c;
    ans[4]=(a+b)*c;
    ans[5]=a*(b+c);
    sort(ans,ans+6);
    cout<<ans[5]<<endl;
    return 0;
}
