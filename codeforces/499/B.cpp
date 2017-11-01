#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,m;
    string s,a,b;
    vector<string>ans;
    vector<pair<string,string>>v;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    for(i=0;i<n;i++){
        cin>>s;
        for(j=0;j<m;j++){
            if(s==v[j].first){
                if(v[j].first.length()<=v[j].second.length()) ans.push_back(v[j].first);
                else ans.push_back(v[j].second);
            }
        }
    }
    for(i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
