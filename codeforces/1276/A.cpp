#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

int alive[N];
char ch[N];
int32_t main()
{
    int t=in();
    while(t--){
        scanf("%s", ch); string s=ch;
        int n=s.size();
        vector<int> ans;
        for(int i=0; i<n; i++) alive[i]=1;
        for(int i=0; i+2<n; i++){
            if(alive[i]&&alive[i+1]&&alive[i+2]){
                if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
                    if(i+3<n&&s[i+3]=='e') alive[i+1]=0, ans.eb(i+1);
                    else alive[i+2]=0, ans.eb(i+2);
                }
                else if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
                    if(i+3<n&&s[i+3]=='o') alive[i+1]=0, ans.eb(i+1);
                    else alive[i+2]=0, ans.eb(i+2);
                }
            }
        }
        printf("%d\n", (int)ans.size());
        for(auto x: ans) printf("%d ", x+1);
        puts("");
        for(int i=0; i<n; i++) alive[i]=0;
    }
    return 0;
}
