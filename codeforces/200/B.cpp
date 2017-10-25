#include<bits/stdc++.h>
using namespace std;
int main()
{
    double k,a,ans=0.0;
    int n;
    cin>>n;
    k=n;
    while(n--){
        cin>>a;
        ans+=a;
    }
    cout<<setprecision(10)<<ans/k<<endl;
    return 0;
}
