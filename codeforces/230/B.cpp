#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int prime(long long int n)
{
    long long int i;
    if(n<2) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(i=3;i<=sqrt(n);i+=2){
        if(n%i==0) return 0;
    }
    return 1;
}
int main()
{
    long long int n,i,k,j,a[100100];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++){
            k=sqrt(a[i]);
        if((k*k==a[i])&&prime(k)==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
