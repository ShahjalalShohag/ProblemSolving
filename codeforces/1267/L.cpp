#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
char s[N];
char w[1005][1005];
int len[1005];


int main()
{
    int n,l,k;
    scanf("%d%d%d",&n,&l,&k);
    scanf("%s",s);
    int m = n*l;
    sort(s, s+m);
    
    int lo = 0,p = 0;

    for (int pos = 0;pos<l;pos++){
        for (int i = lo;i<k;i++){
            w[i][len[i]++] = s[p++];
        }
        while (lo<k && w[lo][pos]<w[k-1][pos]) lo++;
    }

    for (int i =0;i<n;i++){
        while (len[i]<l){
            w[i][len[i]++] = s[p++];
        }
    }

    for (int i = 0;i<n;i++){
        w[i][l] = '\0';
        printf("%s\n",w[i] );
    }
    return 0;
}