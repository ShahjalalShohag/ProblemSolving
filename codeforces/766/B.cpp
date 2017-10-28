#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a[100100];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            if(a[i]+a[j]>a[j+1]){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
