#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,dis,ans;
    string s;
    cin>>s;
    ans=1;
    k=-1;
    int len=s.length();
    for(i=0;i<len;i++){
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y'){
            dis=i-k;
            k=i;
            ans=max(dis,ans);
        }
    }
    ans=max(ans,len-k);
    cout<<ans<<endl;
    return 0;
}
