#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define pf printf
#define sf scanf
#define loop(i, n) for(i=0; i<(n); i++)
#define MAX 100

int main()
{
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    int d;
    while(sf("%d%d%d%d", &x1 , &y1, &x2, &y2)==4)
    {
        if(x1==x2)
        {
            d = abs(y2-y1);
            y3 = y1;
            y4 = y2;
            x3 = x1 + d;
            x4 = x2 + d;
        }
        else if(y1==y2)
        {
            d = abs(x2-x1);
            x3 = x1;
            x4 = x2;
            y3 = y1+d;
            y4 = y2+d;
        }
        else if(abs(x2-x1)==abs(y2-y1))
        {
            x3 = x1;
            y3 = y2;
            x4 = x2;
            y4 = y1;
        }
        else
        {
            pf("-1\n");
            continue;
        }
        pf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    return 0;
}