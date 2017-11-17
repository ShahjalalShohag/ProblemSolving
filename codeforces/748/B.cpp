#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define inf 1<<28
#define pb push_back
#define fr(a,b,c) for(a=b;a<c;a++)
#define eqfr(a,b,c) for(a=b;a<=c;a++)
#define pii pair<int,int>
#define vi vector<int>
#define qi queue<int>
#define itfr(a,b) for(a=b.begin(),a!=b.end(),a++)
#define fill(a,x) memset(a,0,sizeof(a))
#define mpii map<int,int>
#define si set<int>
#define umpii unordered_map<int,int>
#define vit vector<int>::iterator
#define szfr(a,b,c) for(a=b;a<c.size();a++)
#define mpit mapii::iterator
#define umpit umapii::iterator
#define sit si::iteartor
#define vs vector<string>
#define mpsi map<string,int>
#define popf pop_front
#define popb pop_back
#define pf push_front
#define di deque<int>
#define mpr make_pair
#define mpcc map<char,char>
#define umpcc unordered_map<char,char>
#define mpci map<char,int>
int main()
{
    int n,i,j,q,len;
    string s,t;
    cin>>s>>t;
    mpcc mp;
    mpci flag;
    len=s.length();
    for(i=0;i<len;i++){
            if(s[i]=='.') continue;
        if(s[i]==t[i]) {flag[s[i]]=i+1;continue;}
        if(flag[s[i]]!=flag[t[i]]||(flag[s[i]]>0&&flag[t[i]]==0)||(flag[s[i]]==0&&flag[t[i]]>0)){
            cout<<-1<<endl;
            return 0;
        }
        for(j=i+1;j<len;j++){
            if((s[j]==t[i]&&t[j]!=s[i])||(s[j]==s[i]&&t[j]!=t[i])){
                    cout<<-1<<endl;
                    return 0;
                }
                else if(s[j]==t[i]&&s[i]==t[j]){
                    s[j]='.';
                    t[j]='.';
                }
        }
        mp[s[i]]=t[i];
        flag[s[i]]=i+1;
        flag[t[i]]=i+1;
    }
    cout<<mp.size()<<endl;
    for(map<char,char>::iterator it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}

