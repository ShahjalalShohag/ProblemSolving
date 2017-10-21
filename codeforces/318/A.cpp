#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int n,k,j,ans;
    cin>>n>>k;
    j=(n+1)/2;
    if(k<=j) cout<<2*k-1<<endl;
    else cout<<2*k-2*j<<endl;
    return 0;
}
