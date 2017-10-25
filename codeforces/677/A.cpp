#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,a,h,ans=0;
    cin>>n>>h;
    while(n--){
        cin>>a;
        if(a>h) ans+=2;
        else ans++;
    }
    cout<<ans<<endl;
    return 0;

}
