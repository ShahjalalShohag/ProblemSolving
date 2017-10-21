#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i,k,j;
    cin>>s;
    char ch=s[0];
    k=1;
    j=s.length();
    for(i=1;i<j;i++) if(isupper(s[i])==0) k=0;
    if(k==1){
        transform(s.begin(),s.end(),s.begin(),::tolower);
        if(isupper(ch)==1) cout<<s<<endl;
        else{
                cout<<char(toupper(ch));
                string m(s,1,j-1);
                cout<<m<<endl;
        }
    }
    else cout<<s<<endl;
    return 0;
}
