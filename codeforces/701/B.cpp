#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int n,i,j,p,q,k,a[100100]={0},b[100100]={0};
    cin>>n>>k;
    j=n;
    for(i=0;i<k;i++){
       cin>>p>>q;
       n-=!a[p];
       j-=!b[q];
       a[p]=1;
       b[q]=1;
       cout<<n*j<<" ";
    }
    return 0;
}
