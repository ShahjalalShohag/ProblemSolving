#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,i,j,a,cnt=0,ans=0;
    cin>>n;
    while(n--){
        cin>>a;
        if(a>=0) cnt+=a;
        else{
        if(cnt<=0) {
                ans++;
                cnt=0;
        }
        else cnt--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
