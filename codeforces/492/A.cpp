#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    for(i=1;;i++) {
            n-=(i*(i+1))/2;
    if(n<=0) break;
    }
    cout<<(n==0?i:i-1)<<endl;
    return 0;
}
