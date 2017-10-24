#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,ans=0;
    cin>>n;
    for(a=1;a<n;a++) ans+=a*(n-a);
    cout<<ans+n<<endl;
    return 0;
}
