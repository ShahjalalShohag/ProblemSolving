#include<bits/stdc++.h>
using namespace std;
struct shohag
{
    int a,b;
};
bool compare(const shohag& left,const shohag& right)
{
    return left.a<right.a;
}
int main()
{

    shohag dr[100100];
    int s,n;
    cin>>s>>n;
    for(int i=0;i<n;i++) cin>>dr[i].a>>dr[i].b;
    sort(dr,dr+n,compare);
    for(int i=0;i<n;i++){
        if(s>dr[i].a){
            s+=dr[i].b;
        }
        else {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}
