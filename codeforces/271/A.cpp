#include<bits/stdc++.h>
using namespace std;
int beauty(int n)
{

    int a[10]={0},m=4;
    while(m--){
        if(a[n%10]==1) return 0;
        else a[n%10]=1;
        n=n/10;

    }
    return 1;
}
int main()
{

    int n,i,j,ans;
    cin>>n;
    for(i=n+1;;i++){
        if(beauty(i)==1) break;
    }
    cout<<i<<endl;
    return 0;
}
