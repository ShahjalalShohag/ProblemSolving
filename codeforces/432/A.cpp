#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,a[3000],i,team=0;
    cin>>n>>k;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(i=0;i+3<=n;i+=3){
        if(a[i]+k<=5&&a[i+1]+k<=5&&a[i+2]+k<=5) team++;
        else break;
    }
    cout<<team<<endl;
    return 0;
}
