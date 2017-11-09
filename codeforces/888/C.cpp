#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,flag,cnt,len,dom=1000000,ans;
    string s;
    char ch;
    cin>>s;
    len=s.length();
    for(ch='a';ch<='z';ch++){
            ans=0;
            flag=0;
        for(i=0;i<len;){
            if(s[i]==ch){
                    if(flag==0) {ans=i+1;flag=1;}
                    j=i+1;
                while(s[j]!=ch&&j<len){
                    j++;
                }
            cnt=j-i;
            i=j;
            ans=max(ans,cnt);
            }
            else i++;
        }
    if(flag==1) dom=min(dom,ans);
    }
    cout<<dom<<endl;
    return 0;
}
