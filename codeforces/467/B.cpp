#include<bits/stdc++.h>
#include<bitset>
using namespace std;
int main()
{
    int n,m,k,cnt,ans=0,a[10010],i,j;
    string fed,tmp;
    cin>>n>>m>>k;
    for(i=0;i<=m;i++) cin>>a[i];
    fed=bitset<20>(a[m]).to_string();
    for(i=0;i<m;i++){
            cnt=0;
        tmp=bitset<20>(a[i]).to_string();
        for(j=0;j<20;j++){
            if(fed[j]!=tmp[j]) cnt++;
        }
        if(cnt<=k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
