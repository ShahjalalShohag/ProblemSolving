#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<"I hate ";
    for(int i=2;i<=n;i++){
        if(i%2==1) cout<<"that I hate ";
    else cout<<"that I love ";
    }
    cout<<"it\n";
    return 0;
}
