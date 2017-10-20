#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0,i,j;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        if(s[0]=='+'||s[2]=='+') sum++;
        else sum--;
    }
    cout<<sum<<endl;
    return 0;
}
