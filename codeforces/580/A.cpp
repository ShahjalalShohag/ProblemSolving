#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,i,j,max=1,k=1,a[100010];
    cin>>n;
    cin>>a[0];
    for(i=1;i<n;i++){
        cin>>a[i];
        if(a[i]>=a[i-1]) k++;
        else k=1;
        if(k>max) max=k;
    }
    cout<<max<<endl;
    return 0;
}
