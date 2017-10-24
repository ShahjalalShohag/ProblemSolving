#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<0){
        n=abs(n);
        if(n%10>=((n/10)%10)) cout<<-n/10<<endl;
        else cout<<-(n/100)*10-(n%10)<<endl;
        return 0;
    }
    cout<<n<<endl;
    return 0;
}
