#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,ans=1,cnt;
    cin>>n;
    pair<int,int>pr[n];
    for(i=0;i<n;i++) cin>>pr[i].first>>pr[i].second;
    i=0;
    while(i<n-1){
        cnt=1;
        while(i<n-1&&pr[i]==pr[i+1]){
                cnt++;
                i++;
            }
        i++;
        if(ans<cnt) ans=cnt;
    }
    cout<<ans<<endl;
    return 0;
}
