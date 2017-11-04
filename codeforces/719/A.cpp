#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    if(n==1){
        if(a[0]==15) cout<<"DOWN\n";
        else if(a[0]==0) cout<<"UP\n";
        else cout<<-1<<endl;
        return 0;
    }
    if(a[n-1]>a[n-2]){
        if(a[n-1]==15) cout<<"DOWN\n";
        else cout<<"UP\n";
    }
    else{
        if(a[n-1]==0) cout<<"UP\n";
        else cout<<"DOWN\n";
    }
    return 0;
}

