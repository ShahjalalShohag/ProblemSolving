#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,q,m,a;
    vector<int>v;
    cin>>n;
    for(i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
    }
    sort(v.begin(),v.end());
    cin>>q;
    while(q--){
        cin>>m;
        auto x=upper_bound(v.begin(),v.end(),m);
        cout<<x-v.begin()<<endl;
    }
    return 0;
}
