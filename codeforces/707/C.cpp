#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int a,b,c;
    cin>>a;
    if(a==1||a==2) {cout<<-1<<endl; return 0;}
    if(a%2==1){
        b=(a*a-1)/2;
        c=b+1;
    }
    else {
        b=(a*a)/4-1;
        c=b+2;
    }
    cout<<b<<" "<<c<<endl;
    return 0;
}
