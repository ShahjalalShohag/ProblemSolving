#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,a,sum=0;
    vector<int>v;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        if(a%2==0) sum+=a;
        else v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    if(v.size()%2==1) v.pop_back();
    for(auto& x: v) sum+=x;
    cout<<sum<<endl;
    return 0;
}

