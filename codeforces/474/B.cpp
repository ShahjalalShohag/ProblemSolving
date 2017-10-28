#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,m,sum=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) {
            cin>>k;
            sum+=k;
            a[i]=sum;
    }
    int b[sum+1];
    k=0;
    for(i=1;i<=sum;i++){
        if(i>a[k]) k++;
        b[i]=k+1;
    }
    cin>>m;
    for(i=0;i<m;i++){
        cin>>k;
        cout<<b[k]<<endl;
    }
    return 0;
}
