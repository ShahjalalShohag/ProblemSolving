#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=3e5+9;

int32_t main()
{
    int n=in();
    string s;
    cin>>s;
    for(int i=0;i<(int)s.size();i++) s[i]='A'+(s[i]-'A'+n)%26;
    cout<<s<<nl;
    return 0;
}
