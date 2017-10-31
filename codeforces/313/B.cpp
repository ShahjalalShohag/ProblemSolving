#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,i,len,cnt=0,j,m,n,a[100100];
    string s;
    cin>>s;
    len=s.length();
    a[1]=0;
    for(i=1;i<len;i++){
        cnt+=(s[i]==s[i-1]);
        a[i+1]=cnt;
    }
    cin>>q;
    while(q--){
        cin>>m>>n;
        cout<<a[n]-a[m]<<endl;
    }
    return 0;
}
