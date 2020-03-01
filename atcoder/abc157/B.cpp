#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

int a[3][3];
set<int> se;
int32_t main()
{
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> a[i][j];
    int n ; cin >> n;
    while(n--){
        int k ; cin >> k; se.insert(k);
    }
    for(int i = 0; i < 3; i++){
        int ok = 1;
        for(int j = 0; j < 3; j++) ok &= se.find(a[i][j]) != se.end();
        if(ok) return cout << "Yes\n", 0;
    }
    for(int i = 0; i < 3; i++){
        int ok = 1;
        for(int j = 0; j < 3; j++) ok &= se.find(a[j][i]) != se.end();
        if(ok) return cout << "Yes\n", 0;
    }
    if(se.find(a[1][1]) != se.end() && se.find(a[2][2]) != se.end() && se.find(a[0][0]) != se.end()) return cout << "Yes\n", 0;
    if(se.find(a[2][0]) != se.end() && se.find(a[1][1]) != se.end() && se.find(a[0][2]) != se.end()) return cout << "Yes\n", 0;
    cout << "No\n";
    return 0;
}
