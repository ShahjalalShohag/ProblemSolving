#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int pre[N], suf[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, c; cin >> n >> k >> c;
    string s; cin >> s;
    vector<int> v;
    for(int i = 0; i < n; i++) if(s[i] == 'o') v.push_back(i);
    for(int i = 0; i < v.size(); i++){
        int l = 0, r = i - 1, nw = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(v[mid] < v[i] - c) nw = mid, l = mid + 1;
            else r = mid - 1;
        }
        pre[i] = 1;
        if(nw != -1) pre[i] += pre[nw];
    }
    for(int i = (int)v.size() - 1; i >= 0; i--){
        int l = i + 1, r = (int)v.size() - 1, nw = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(v[mid] > v[i] + c ) nw = mid, r = mid - 1;
            else l = mid + 1;
        }
        suf[i] = 1;
        if(nw != -1) suf[i] += suf[nw];
    }
    vector<int> ans;
    for(int i = 0; i < v.size(); i++){
        int id = -1;
        if(i){
            int l = 0, r = i - 1, nw = i - 1;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(pre[mid] == pre[i - 1]) nw = mid, r = mid - 1;
                else l = mid + 1;
            }
            l = i + 1, r = (int)v.size() - 1;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(v[mid] > v[nw] + c ) id = mid, r = mid - 1;
                else l = mid + 1;
            }
        }
        else id = i + 1;
        int res = 0;
        if(i) res = pre[i - 1];
        if(id != -1) res += suf[id];
        if(res < k) ans.push_back(v[i]);
    }
    for(auto x: ans) cout << x + 1 << '\n';
    return 0;
}
