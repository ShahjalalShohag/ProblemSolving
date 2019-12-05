#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+6;

vector<int> divi[N];
int cnt[N],divcnt[N],val[N];

int main()
{

    int tc;scanf("%d",&tc);
    while (tc--)
    {
        int n; scanf("%d",&n);

        for (int i = 0;i<=n;i++){
            cnt[i] = 0;
            val[i] = 0;
            divcnt[i] = 0;
        }
        for (int i = 0;i<n;i++){
            int c; scanf("%d",&c);
            cnt[c]++;
        }
        vector<int> v;
        int mn = n;
        for (int i = 0;i<=n;i++) if (cnt[i]){
            v.push_back(cnt[i]);
            mn = min(mn,cnt[i]);
            //cout<<cnt[i]<<endl;
        }
        mn++;
        int ans = n;
        for (int s = 2;s<=mn;s++){
            int cost = 0, ok = 0;
            for (int a: v){
                for (int i = 0;i*(s-1)<=a;i++){
                    if ((a-i*(s-1))%s==0){
                        ok++;
                        cost+=i + (a-i*(s-1))/s;
                        break;
                    }
                }
            }
            if (ok==(int)v.size()) {
                ans = min(ans,cost);
                //cout<<s<<" "<<cost<<" "<<ok<<endl;
            }
        }
        printf("%d\n",ans );
    }
    return 0;

}