#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=3e5+9;

string s[]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int32_t main()
{
    string p;
    cin>>p;
    int ans=0;
    for(int i=0;i<7;i++) if(s[i]==p){
        for(i=(i+1)%7;s[i]!="SUN";i=(i+1)%7) ans++;
        cout<<ans+1<<nl;
        return 0;
    }
    return 0;
}

