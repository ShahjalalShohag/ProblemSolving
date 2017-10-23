#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if((i+1)%2==1||j==0&&(i+1)%4==0||j==m-1&&(i+1)%4!=0) cout<<'#';
            else cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}
