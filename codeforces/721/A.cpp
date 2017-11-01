#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,cnt;
    string s;
    vector<int>v;
    cin>>n>>s;
    for(i=0;i<n;){
        if(s[i]=='W') {i++;continue;}
        cnt=0;
        while(s[i]=='B'){
            cnt++;
            i++;
        }
        v.push_back(cnt);
    }
    if(v.empty()==1){cout<<0<<endl;return 0;}
    cout<<v.size()<<endl;
    for(i=0;i<v.size()-1;i++) cout<<v[i]<<" ";
    cout<<v.back()<<endl;
    return 0;
}
