#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[4],i;
    for(i=0;i<3;i++)cin>>a[i];
    sort(a,a+3);
    cout<<a[2]-a[0]<<endl;
    return 0;
}
