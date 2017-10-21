#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0,i,a[200]={0};
    string s;
    cin>>s;
    for(i=0;i<s.length();i++){
            int k=int(s[i]);
            if(a[k]==0){
                n++;
                a[k]=1;
            }
    }
    if(n%2==0) cout<<"CHAT WITH HER!\n";
    else cout<<"IGNORE HIM!\n";
    return 0;
}
