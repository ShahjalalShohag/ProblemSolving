#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,k,a,cnt,count=0;
    cin>>n;
    while(n--){
            k=3;
            cnt=0;
        while(k--){
            cin>>a;
    if(a==1) cnt++;
        }
        if(cnt>1) count++;
    }
    cout<<count;
    return 0;
}
