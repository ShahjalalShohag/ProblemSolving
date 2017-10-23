#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0,i;
    string s;
    cin>>s;
    for(i=0;i<s.length();i++){
        if(s[i]>='a') n++;
    }
    if(s.length()-n>n) {
        transform(s.begin(),s.end(),s.begin(),::toupper);
        cout<<s<<endl;
    }
    else{
        transform(s.begin(),s.end(),s.begin(),::tolower);
        cout<<s<<endl;
    }
    return 0;
}
