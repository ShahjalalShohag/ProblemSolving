#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k256,k32,k2,k3,k5,k6;
    cin>>k2>>k3>>k5>>k6;
    k256=min(k2,min(k5,k6));
    k32=min(k3,(k2-k256));
    cout<<k256*256+k32*32<<endl;
    return 0;
}
