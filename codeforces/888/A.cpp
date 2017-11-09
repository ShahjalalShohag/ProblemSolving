#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n,i,cnt=0,a[1100];
     cin>>n;
     for(i=0;i<n;i++) cin>>a[i];
     for(i=1;i<n-1;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]) cnt++;
        else if(a[i]<a[i-1]&&a[i]<a[i+1]) cnt++;
     }
     cout<<cnt<<endl;
     return 0;
 }

