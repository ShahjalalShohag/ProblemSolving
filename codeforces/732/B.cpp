#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,prev,current,m,extra=0,a[1000];
    vector<int>v;
    cin>>n>>k;
    for(i=0;i<n;i++) cin>>a[i];
    prev=a[0];
    v.push_back(prev);
    for(i=1;i<n;i++){
        current=a[i];
        if(prev+current>=k){
                prev=current;
                v.push_back(current);
        }
        else{
            m=k-prev-current;
            extra+=m;
            v.push_back(m+current);
            prev=m+current;
        }
    }
    cout<<extra<<endl;
    for(auto& x: v) cout<<x<<" ";
    cout<<endl;
    return 0;
}
