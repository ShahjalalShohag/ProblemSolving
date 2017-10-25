#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(360%(180-n)==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
