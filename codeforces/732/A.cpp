#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,r,i;
    cin>>k>>r;
    for(i=k;;i+=k){
        if((i-r)%10==0||i%10==0) break;
    }
    cout<<i/k<<endl;
    return 0;
}
