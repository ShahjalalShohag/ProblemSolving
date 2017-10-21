#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int k,n,w,ans,i,j;
    cin>>k>>n>>w;
    ans=(w*(w+1))/2;
    ans*=k;
    if(ans>n) cout<<ans-n<<endl;
    else cout<<0<<endl;
    return 0;
}
