#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[110],i,even=0,odd=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==1) odd++;
        else  even++;
    }
    if(odd>even){
        for(i=0;i<n;i++) {
            if(a[i]%2==0) {
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    else{
        for(i=0;i<n;i++){
            if(a[i]%2==1){
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
}
