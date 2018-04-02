#include<bits/stdc++.h>
using namespace std;
#define ll long long
char v[510][510];
bool vis[510][510];
ll k;
ll nodex,nodey,n,m;
void yo()
{
    ll i,j,mx=1e18;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(v[i][j]=='.'){
                ll cnt=(v[i-1][j]=='.')+(v[i][j-1]=='.')+(v[i+1][j]=='.')+(v[i][j+1]=='.');
                if(cnt<mx) mx=cnt,nodex=i,nodey=j;
            }
        }
    }
}
void dfs(ll i,ll j)
{
    if(i<=0||j<=0||i>n||j>m) return;
    if(vis[i][j]) return;
    vis[i][j]=1;
    k--;
    if(k==0){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(v[i][j]=='.'){
                    if(vis[i][j]) cout<<v[i][j];
                    else cout<<'X';
                }
                else cout<<v[i][j];
            }
            cout<<endl;
        }
        exit(0);
    }
    if(v[i+1][j]=='.') dfs(i+1,j);
    if(v[i-1][j]=='.') dfs(i-1,j);
    if(v[i][j+1]=='.') dfs(i,j+1);
    if(v[i][j-1]=='.') dfs(i,j-1);
}
int main()
{
    ll i,j,cnt=0;
    cin>>n>>m>>k;
    string s;
    for(i=1;i<=n;i++){
        cin>>s;
        for(j=1;j<=m;j++){
            v[i][j]=s[j-1];
            if(s[j-1]=='.') cnt++;
        }
    }
    yo();
    k=cnt-k;
    dfs(nodex,nodey);
}
