#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p,q,ans=0;
    cin>>n;
    while(n--){
        cin>>p>>q;
        if(q-p>1) ans++;
    }
    cout<<ans;
    return 0;
}
