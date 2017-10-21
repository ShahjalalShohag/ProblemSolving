#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,a,i,j,ans=0,num[5];
    for(i=1;i<5;i++) num[i]=0;
    cin>>n;
    while(n--){
        cin>>a;
        num[a]++;
    }
    ans=num[4]+num[3]+num[2]/2;
    num[1]-=num[3];
    if(num[2]%2==1){
            ans++;
        num[1]-=2;
    }
    if(num[1]>0) ans+=(num[1]+3)/4;
    cout<<ans<<endl;
    return 0;
}
