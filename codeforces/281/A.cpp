#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k=s.length()-1;
    string ss(s,1,k);
    cout<<char(toupper(s[0]))<<ss<<endl;
    return 0;
}
