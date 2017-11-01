#include<bits/stdc++.h>
using namespace std;
struct sj
{
    int price,quality;
};
bool compare(sj left,sj right){return left.price<right.price;}
int main()
{
    int n,i,j,flag=0;
    sj a[100100];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i].price>>a[i].quality;
    }
    sort(a,a+n,compare);
    for(i=0;i<n-1;i++){
        if(a[i].quality>a[i+1].quality) {flag=1;break;}
    }
    if(flag==1) cout<<"Happy Alex\n";
    else cout<<"Poor Alex\n";
    return 0;
}
