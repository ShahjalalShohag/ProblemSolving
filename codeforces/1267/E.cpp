

#include <bits/stdc++.h>
using namespace std;
#define mx 400000

int ara[200][200];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for(int j=1;j<=m;j++)
   {
     for(int i=1;i<=n;i++)
     {
        scanf("%d",&ara[i][j]);
     }
   }
   int ans=m;
   vector<int>ou;
   for(int i=1;i<=m;i++)ou.push_back(i);
   for(int i=1;i<n;i++)
   {
      vector<pair<int,int>>vc;
      int sum=0;
      for(int j=1;j<=m;j++)
      {
          sum+=ara[i][j]-ara[n][j];
          vc.push_back({ara[i][j]-ara[n][j],j});
      }
      sort(vc.begin(),vc.end());
      int cnt=0;
      vector<int>tp;
      for(int j=0;j<m&&sum<0;j++)
      {
           sum-=vc[j].first;
           cnt++;
           tp.push_back(vc[j].second);
      }
      if(ans<=cnt)continue;
      ans=min(ans,cnt);
      ou.clear();
      ou=tp;
   }
   cout<<ans<<endl;
   for(int j=0;j<ou.size();j++)
   {
      printf("%d ",ou[j]);
   }


}

