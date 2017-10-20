#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,k,a[100],i,count=0;
    cin>>n>>k;
    k=k-1;
    for(i=0;i<n;i++) cin>>a[i];
    if(a[k]!=0){
    for(i=k+1;i<n;i++){
        if(a[i]==a[k]) count++;
    }
    cout<<k+1+count<<endl;
    }
    else{
        for(i=0;i<k;i++) if(a[i]>a[k]) count++;
        cout<<count<<endl;
    }
    return 0;
}
