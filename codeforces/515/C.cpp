#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k;
    string s;
    vector<int>v;
    vector<int>::reverse_iterator it;
    cin>>n;
    cin>>s;
    for(i=0;i<n;i++){
        if (s[i]=='0'||s[i]=='1') continue;
        switch(s[i])
        {
        case '2':
        case '3':
        case '5':
        case '7':
            k=s[i]-'0';
            v.push_back(k);
            break;
        case '4':
            k=s[i]-'0';
            for(j=1;j<=2;j++) v.push_back(2);
            k--;
            v.push_back(k);
            break;
        case '8':
            k=s[i]-'0';
            for(j=1;j<=3;j++) v.push_back(2);
            k--;
            v.push_back(k);
            break;
        case '6':
            v.push_back(3);
            v.push_back(5);
            break;
        case '9':
            v.push_back(2);
            v.push_back(3);
            v.push_back(3);
            v.push_back(7);
            break;
        }
    }
    sort(v.begin(),v.end());
    for(it=v.rbegin();it!=v.rend();it++) cout<<*it;
    cout<<endl;
    return 0;
}
