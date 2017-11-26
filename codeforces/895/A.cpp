#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans,n,a[100005];
    ans=360;
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j<=n;j++)
	    {
			sum+=a[j];
			ans=min(ans,abs(360-2*sum));
		}
	}
	cout<<ans;
}