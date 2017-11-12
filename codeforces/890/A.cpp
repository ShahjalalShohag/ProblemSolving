#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,ans,sum=0,a[10];
    for(i=0;i<6;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(i=0;i<4;i++){
        for(j=i+1;j<5;j++){
            for(k=j+1;k<6;k++){
                ans=a[i]+a[j]+a[k];
                if(ans==sum-ans){
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
