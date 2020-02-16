#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5 + 9;
const int mod = 1e9 + 7;
const ll inf = 1e18;

ll yo(vector<ll> a, vector<ll> b, ll x)
{
    if(x < 0) reverse(a.begin(), a.end());
    int r = (int)b.size() - 1;
    ll ans = 0;
    for(int l = 0; l < a.size(); l++){
        while(r >=0 && a[l] * b[r] > x) r--;
        ans += r + 1;
    }
    return ans;
}
ll yo1(vector<ll> a, ll x)
{
    ll p = a.size();
    ll ans = yo(a, a, x) ;
    for(int i = 0; i < (int)a.size(); i++) ans -= a[i] * a[i] <= x;
    return ans / 2;
}
int a[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    //vector<ll> a = {0, 0, 0, 0 ,0, 2, 3, 4, 5}, b = {1, 2, 3 };
    //cout << yo1(a, 500000000000) << nl;
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> pos, neg, nn;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] >= 0) pos.eb(a[i]);
        else neg.eb(-a[i]), nn.eb(a[i]);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    sort(nn.begin(), nn.end());
    ll l = - inf, r = inf, ans;
    while(l <= r){
        ll mid = (l + r) / 2;
        //deb(mid);
        ll cnt = 0;
        if(mid >= 0){
            cnt = yo1(pos, mid) + yo1(neg, mid) + (ll)pos.size() * (ll)neg.size();
        }
        else{
            cnt = yo(pos, nn, mid);
        }
        //deb(cnt);
        if(cnt >= k){
            ans = mid; r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << nl;
    return 0;
}
