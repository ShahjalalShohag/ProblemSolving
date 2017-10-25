#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a[5100],b[5100],c[5100],p=0,q=0,r=0,t,m,u;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        if(m==1){
            a[p]=i+1;
            p++;
        }
        else if(m==2){
            b[q]=i+1;
            q++;
        }
        else{
            c[r]=i+1;
            r++;
        }
    }
    t=min(p,min(q,r));
    cout<<t<<endl;
    for(p=0;p<t;p++) cout<<a[p]<<" "<<b[p]<<" "<<c[p]<<endl;
    return 0;
}


