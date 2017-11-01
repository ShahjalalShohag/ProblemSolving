#include<bits/stdc++.h>
using namespace std;
long long int comb(long long int n)
{
    if (n<2) return 0;
    else return n*(n-1)/2;
}
int main()
{
    long long int n,m,mx,mn;
    cin>>n>>m;
    mn=(comb(n/m))*(m-n%m)+comb((n/m+1))*(n%m);
    mx=comb(n-m+1);
    cout<<mn<<" "<<mx<<endl;
    return 0;
}
