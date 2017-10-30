#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,cnt=0,j,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        char si[20];
        cin>>si;
    if(si[0]=='T')
           cnt+=4;
        else if(si[0]=='C')
            cnt+=6;
        else if(si[0]=='O')
            cnt+=8;
        else if(si[0]=='D')
            cnt+=12;
        else if(si[0]=='I')
            cnt+=20;
    }
    printf("%d\n",cnt);
    return 0;
}