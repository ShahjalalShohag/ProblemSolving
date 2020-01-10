#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

///returns the longest proper prefix array of pattern p
///where lps[i]=longest proper prefix which is also suffix of p[0...i]
vector<int> build_lps(vector<int> p)
{
    int sz = p.size();
    vector<int> lps;
    lps.assign(sz + 1, 0);
    int j = 0;
    lps[0] = 0;
    for(int i = 1; i < sz; i++)
    {
        while(j >= 0 && p[i] != p[j])
        {
            if(j >= 1) j = lps[j - 1];
            else j = -1;
        }
        j++;
        lps[i] = j;
    }

    return lps;
}
vector<int>ans;
///returns matches in vector ans in 0-indexed
void kmp(vector<int> lps, vector<int> s, vector<int> p)
{
	int psz = p.size(), sz = s.size();
	int j = 0;
	for(int i = 0; i < sz; i++)
	{
		while(j >= 0 && p[j] != s[i])
			if(j >= 1) j = lps[j - 1];
			else j = -1;

		j++;
		if(j == psz)
		{
			j = lps[j - 1];
			///pattern found in vector<int> s at position i-psz+1
            ans.eb(i-psz+1);
		}
		///after each loop we have j=longest common suffix of s[0..i] which is also prefix of p
	}
}

int a[N], b[N];
vector<int> c, d;
int32_t main()
{
    int n=in();
    for(int i=0; i<n; i++) a[i]=in();
    for(int i=0; i<n; i++) b[i]=in();
    for(int i=0; i<n; i++) c.eb(a[i]^a[(i+1)%n]);
    for(int i=0; i<n; i++) d.eb(b[i]^b[(i+1)%n]);
//    for(auto x: c) cout<<x<<' ';
//    cout<<nl;
//    for(auto x: d) cout<<x<<' ';
//    cout<<nl;
    auto p=d;
    for(auto x: p) d.eb(x);
    vector<int> lps=build_lps(c);
    kmp(lps, d, c);
    reverse(ans.begin(), ans.end());
    for(auto x: ans){
        if(x){
            cout<<n-x<<' '<<(a[0]^b[x%n])<<nl;
        }
    }
    return 0;
}
