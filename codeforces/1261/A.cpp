#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=3e5+9;
const int mod=1e9+7;


int32_t main()
{
    int t=in();
    while(t--){
        int n=in(),k=in();
        string s;
        cin>>s;
        string p;
        for(int i=0;i<k-1;i++) p+="()";
        int baki=n-2*(k-1);
        for(int i=0;i<baki/2;i++) p+='(';
        for(int i=0;i<baki/2;i++) p+=')';
        //deb(p);
        vector<pii> ans;
        for(int i=0;i<n;i++){
            if(s[i]!=p[i]){
                for(int j=i+1;j<n;j++){
                    if(s[j]==p[i]){
                        ans.eb(i,j);
                        reverse(s.begin()+i,s.begin()+j+1);
                        break;
                    }
                }
            }
        }
        //deb(s);
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d %d\n",x.first+1,x.second+1);
    }
    return 0;
}
