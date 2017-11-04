#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a;
    vector<int>v;
    map<int,int>mp;
    cin>>n;
    for(i=0;i<n;i++){
            cin>>a;
            mp[a]++;
            v.push_back(a);
    }
    auto x=max_element(mp.begin(),mp.end(),[](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });
    cout<<x->second<<" ";
    cout<<mp.size()<<endl;
    return 0;

}
