#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    int k=n;
    for(int i=5;i>0&&k>0;i--){
        ans+=k/i;
        k-=i*(k/i);
    }
    cout<<ans<<endl;
    return 0;
}
