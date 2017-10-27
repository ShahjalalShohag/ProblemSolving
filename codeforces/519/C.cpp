#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0,m;
    cin>>n>>m;
    while(n&&m){
        if(n>m){
            if(n>=2){
                n-=2;
                m--;
                ans++;
            }
            else break;
        }
        else{
            if(m>=2){
                m-=2;
                n--;
                ans++;
            }
            else break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
