#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,c=0,a[10];
    for(i=0;i<4;i++) cin>>a[i];
    sort(a,a+4);
    for(i=0;i<3;i++){
        if(a[i]==a[i+1]) c++;
    }
    cout<<c<<endl;
    return 0;
}
