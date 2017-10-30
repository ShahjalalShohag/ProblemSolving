#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,a[200200];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    cout<<a[n-1]-a[0]<<" ";
    i=count(a,a+n,a[0]);
    j=count(a,a+n,a[n-1]);
    if(a[0]==a[n-1]){
        cout<<(i*(i-1))/2<<endl;
        return 0;
    }
    cout<<i*j<<endl;
    return 0;
}
