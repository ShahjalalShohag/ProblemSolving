

#include <bits/stdc++.h>
using namespace std;
#define mx 400000

int ara[mx],ran,val[mx];
char str[mx];
int func(int pos,int pos2)
{
   if(pos<0&&pos2>=ran)return 1;
   if(pos<0)return 0;
   if(pos2>=ran)return 0;
   if(ara[pos]!=ara[pos2])return 0;
   if(val[pos]+val[pos2]<=2)return 0;
   return func(pos-1,pos2+1);
}
int main()
{
   int n;
    scanf("%s",str);
    n=strlen(str);
    for(int i=0;i<n;)
    {
       int cnt=0,j;
       for(j=i;j<n&&str[i]==str[j];j++)
       {
          cnt++;
       }
       ara[ran]=str[i]-64;
       val[ran++]=cnt;
       i=j;
    }
    if(ran%2==0)
    {
       printf("0\n");
       return 0;
    }
  //  cout<<ran<<endl;
    int g=ran/2;
  //  cout<<val[g]<<endl;
    if(val[g]>=2)
    {
        int ans=func(g-1,g+1)*(val[g]+1);
        cout<<ans<<endl;
        return 0;
    }
    cout<<"0"<<endl;



}

