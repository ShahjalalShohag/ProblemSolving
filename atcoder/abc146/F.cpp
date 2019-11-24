#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )
#define stree mid=(b+e)>>1,l=2*n,r=l+1
const int N=1e5+9;

struct segtree
{
    int t[4*N];
    void build(int n,int b,int e)
    {
        if(b==e){
            t[n]=1e9;
            return;
        }
        int stree;
        build(l,b,mid);
        build(r,mid+1,e);
        t[n]=min(t[l],t[r]);
    }
    void upd(int n,int b,int e,int i,int x)
    {
        if(b>i||e<i) return;
        if(b==e&&b==i){
            t[n]=x;
            return;
        }
        int stree;
        upd(l,b,mid,i,x);
        upd(r,mid+1,e,i,x);
        t[n]=min(t[l],t[r]);
    }
    int query(int n,int b,int e,int i,int j)
    {
        if(b>j||e<i) return 1e9;
        if(b>=i&&e<=j) return t[n];
        int stree;
        int a=query(l,b,mid,i,j);
        int p=query(r,mid+1,e,i,j);
        return min(a,p);
    }
}t;

int nxt[N];
int32_t main()
{
    int n=in(),m=in();
    char ch[n+1];
    scanf("%s",ch);
    string s=ch;
    t.build(1,1,n);
    t.upd(1,1,n,n,0);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            int l=i+1, r=min(n,i+m);
            int ans=t.query(1,1,n,l,r)+1;
            int nw=0;
            while(l<=r){
                int mid=(l+r)/2;
                if(t.query(1,1,n,l,mid)+1==ans) nw=mid,r=mid-1;
                else l=mid+1;
            }
            nxt[i]=nw;
            //cout<<i<<' '<<ans<<' '<<nw<<nl;
            t.upd(1,1,n,i,min((int)1e9,ans));
        }
    }
    int ans=t.query(1,1,n,1,min(n,m));
    if(ans==1e9) puts("-1");
    else{
        printf("%d",nxt[0]);
        int pre=nxt[0];
        for(int i=nxt[pre];pre<n;i=nxt[i]){
            printf(" %d",i-pre);
            pre=i;
        }
        puts("");
    }
    return 0;
}
