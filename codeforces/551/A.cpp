#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a,k;
    vector<int>v;
    map<int,int>mp;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
        mp[a]++;
    }
    i=1;
    for(map<int,int>::reverse_iterator rit=mp.rbegin();rit!=mp.rend();rit++){
            k=rit->second;
            rit->second=i;
            i+=k;
    }
    for(i=0;i<n;i++) cout<<mp[v[i]]<<" ";
    cout<<endl;
    return 0;
}
