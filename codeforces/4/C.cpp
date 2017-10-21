#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    map<string,int>mp;
    cin>>n;
    while(n--){
        cin>>s;
        if(mp.count(s)==0){
            cout<<"OK\n";
            mp[s]=1;
        }
        else{
            cout<<s<<mp[s]<<endl;
            mp[s]+=1;
        }
    }
    return 0;
}
