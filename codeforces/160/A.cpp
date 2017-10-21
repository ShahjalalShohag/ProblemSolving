#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,i,a[110],sum=0,max=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n,greater<int>());
    for(i=0;i<n;i++){
        max+=a[i];
        if(max>sum/2)break;
    }
    cout<<i+1<<endl;
    return 0;
}

