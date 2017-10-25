#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j=0;
    for(i=0;i<5;i++){
        cin>>n;
        j+=n;
    }
    if(j%5==0&&j!=0) cout<<j/5<<endl;
    else cout<<-1<<endl;
    return 0;
}
