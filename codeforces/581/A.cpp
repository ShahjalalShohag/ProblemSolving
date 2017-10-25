#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,b,mn;
    cin>>r>>b;
    mn=min(r,b);
    cout<<mn<<" ";
    cout<<abs(r-b)/2<<endl;
    return 0;
}
