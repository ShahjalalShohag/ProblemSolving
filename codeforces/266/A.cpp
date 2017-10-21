#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0,i,j;
    string s;
    cin>>j;
    cin>>s;
    for(i=1;i<s.length();i++){
        if(s[i]==s[i-1]) n++;
    }
    cout<<n<<endl;
    return 0;
}
