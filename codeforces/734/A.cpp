#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    string s;
    cin>>n;
    cin>>s;
    int i=count(s.begin(),s.end(),'A');
    if(n-i>i) cout<<"Danik\n";
    else if(n-i<i) cout<<"Anton\n";
    else cout<<"Friendship\n";
    return 0;
}
