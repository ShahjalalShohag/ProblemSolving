#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,jokes,sum=0,k,d;
    cin>>n>>d;
    for(i=0;i<n;i++){
        cin>>j;
        sum+=j;
    }
    k=sum+(n-1)*10;
    if(k>d){
        cout<<-1<<endl;
        return 0;
    }
    jokes=2*(n-1)+(d-k)/5;
    cout<<jokes<<endl;
    return 0;
}
