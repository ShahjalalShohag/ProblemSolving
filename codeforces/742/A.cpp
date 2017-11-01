#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans;
    cin>>n;
    if(n==0){
        cout<<1<<endl;
        return 0;
    }
    switch(n%4)
    {
    case 1:
        ans=8;
        break;
    case 2:
        ans=4;
        break;
    case 3:
        ans=2;
        break;
    case 0:
        ans=6;
        break;
    }
    cout<<ans<<endl;
    return 0;
}
