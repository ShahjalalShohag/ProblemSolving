#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 3e5 + 9, M=1e9;
const int mod = 1e9 + 7;
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
int x[N], y[N];
int32_t main()
{
    int n=in(), sx=in(), sy=in();
    for(int i=1; i<=n; i++) x[i]=in(), y[i]=in();
    int ans=0, ax, ay;
    for(int i=0; i<8; i++){
        int nx=sx+dx[i];
        int ny=sy+dy[i];
        if(nx>=0&&nx<=M&&ny>=0&&ny<=M){
            int cnt=0;
            for(int i=1; i<=n; i++){
                if(1LL*dist(sx, sy, nx, ny)+dist(nx, ny, x[i], y[i])==1LL*dist(sx, sy, x[i], y[i])) cnt++;
            }
            if(cnt>= ans){
                ans=cnt;
                ax=nx;
                ay=ny;
            }
        }
    }
    cout<<ans<<nl<<ax<<' '<<ay<<nl;
    return 0;
}
