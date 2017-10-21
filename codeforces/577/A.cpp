#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,x,i,j=0;
    cin>>n>>x;
    for(i=1;i<=n;i++){
        if(x%i==0&&x/i<=n) j++;
    }
    cout<<j<<endl;
    return 0;
}
