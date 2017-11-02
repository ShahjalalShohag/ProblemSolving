#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,cnt[200]={0},a[100100];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++){
            if(a[i]==25) cnt[25]++;
            else if(a[i]==50){
                if(cnt[25]>=1){
                    cnt[25]--;
                    cnt[50]++;
                }
                else{
                    cout<<"NO\n";
                    return 0;
                }
            }
            else{
                if(cnt[25]>=1&&cnt[50]>=1){
                    cnt[25]--;
                    cnt[50]--;
                }
                else if(cnt[25]>=3){
                    cnt[25]-=3;
                }

                else{
                    cout<<"NO\n";
                    return 0;
                }
            }
    }
    cout<<"YES\n";
    return 0;
}
