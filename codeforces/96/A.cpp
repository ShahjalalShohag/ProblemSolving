#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,s0,s1;
    string s;
    cin>>s;
    for(i=0;i<s.length();){
            s0=0;
            s1=0;
        while(s[i]=='0'){
            i++;
            s0++;
            if(s0==7) goto shit;
        }
        while(s[i]=='1'){
            i++;
            s1++;
            if(s1==7) goto shit;
        }
    }
    shit:
        if(s0==7||s1==7) cout<<"YES\n";
        else cout<<"NO\n";
        return 0;
}
