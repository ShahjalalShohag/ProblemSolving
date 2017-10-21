#include<bits/stdc++.h>
using namespace std;
int main()
{

    int m,n,i,j,a[6][6];
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            cin>>a[i][j];
            if(a[i][j]>0) {m=i;n=j;}
        }
    }
    cout<<abs(m-3)+abs(n-3)<<endl;
    return 0;
}
