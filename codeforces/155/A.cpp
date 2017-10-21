#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,mx,mn,ama=0;
    cin>>n>>mn;
    mx=mn;
    n=n-1;
    while(n--){
            cin>>m;
            if(m>mx){
                ama++;
                mx=m;
            }
            else if(m<mn){
                ama++;
                mn=m;
            }
    }
    cout<<ama<<endl;
    return 0;
}
