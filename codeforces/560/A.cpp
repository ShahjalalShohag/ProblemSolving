#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a;
    set<int>s;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        s.insert(a);
    }
    if(s.count(1)) cout<<-1<<endl;
    else cout<<1<<endl;
    return 0;
}
