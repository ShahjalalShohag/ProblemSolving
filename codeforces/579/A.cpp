#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,ans=0;
    cin>>n;
    for(i=n;i>=1;i/=2){
        if(i%2==1) {
                ans++;
                i--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
