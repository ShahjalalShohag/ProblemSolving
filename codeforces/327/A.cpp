#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,i,j,a,c1=0,c0=0,mx=-1 ;
    cin>>n;
    while(n--){
        cin>>a;
        if(a==1){
            c1++;
            if(c0>0){
                c0--;
            }
        }
        else{
            c0++;
            if(c0>mx) mx=c0;
        }
    }
    cout<<c1+mx<<endl;
    return 0;
}
