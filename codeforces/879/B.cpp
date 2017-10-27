#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
template<class T> inline void read(T &_a){
    bool f=0;int _ch=getchar();_a=0;
    while(_ch<'0' || _ch>'9'){if(_ch=='-')f=1;_ch=getchar();}
    while(_ch>='0' && _ch<='9'){_a=(_a<<1)+(_a<<3)+_ch-'0';_ch=getchar();}
    if(f)_a=-_a;
}

const int maxn=501;
deque<int>a;
long long n,k,cnt;

int main()
{
    read(n); read(k);
    for (register int i=1,v;i<=n;++i) read(v),a.push_back(v);
    if(k<n)
    {
        int a1,a2;
        while(cnt<k)
        {
            a1=a.front(); a.pop_front();
            a2=a.front(); a.pop_front();
            if(a1>a2)
            {
                ++cnt;
                a.push_front(a1);
                a.push_back(a2);
            } else {
                cnt=1;
                a.push_front(a2);
                a.push_back(a1);
            }
        }
        printf("%d",a.front());
    } else {
        int maxx=0;
        while(!a.empty())
        {
            maxx=max(maxx,a.front());
            a.pop_front();
        }
        printf("%d",maxx);
    }
    return 0;
}