#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,ta=0,tmp=-1,tb=0,a;
    set<int>s;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        if(a==0) s.insert(a);
        else if(a==100) s.insert(a);
        else if(!ta&&a%10==0){
            s.insert(a);
            ta=1;
        }
        else if(!tb&&a<10){
            s.insert(a);
            tb=1;
        }
        else tmp=a;
    }
    if(!ta&&!tb&&tmp>0) s.insert(tmp);
    cout<<s.size()<<endl;
    for(auto& x:s) cout<<x<<" ";
    cout<<endl;
    return 0;
}
