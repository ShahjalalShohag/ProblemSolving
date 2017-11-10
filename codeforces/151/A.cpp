#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,k,ml,lime,slice,perdrink,persalt,salt;
    cin>>n>>k>>ml>>lime>>slice>>salt>>perdrink>>persalt;
    a=(k*ml)/(perdrink*n);
    b=(lime*slice)/n;
    c=salt/(persalt*n);
    cout<<min(a,min(b,c))<<endl;
    return 0;
}
