#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
int check(lli mm,vector<lli>vec,lli k,lli n,vector<lli>dp);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		lli n,q,i;
		cin>>n>>q;
		vector<lli>vec;
		for(i=0;i<n;i++)
		{
			lli l;
			cin>>l;
			vec.push_back(l);
		}
		lli k;
		cin>>k;

		sort(vec.begin(),vec.end());
		vector<lli>dp(n,0);
		dp[0]=vec[0];

		for(i=1;i<n;i++)
			dp[i]=dp[i-1]+vec[i];

		lli lb=0,ub=n+1,ans=0;
		while(lb<=ub)
		{
			lli mm=lb+(ub-lb)/2;
			if(check(mm,vec,k,n,dp))
			{
				ans=mm;
				lb=mm+1;
			}
			else
				ub=mm-1;
		}
		cout<<ans<<endl;
	}
}
int check(lli mm,vector<lli>vec,lli k,lli n,vector<lli>dp)
{
	// vector<lli>len;
	// for(i=0;i<vec.size();i++)
	// 	len.push_back(vec[i]);
	// for(i=0;i<vec.size();i++)
	// {
	// 	if(vec[i]>=k)
	// 		cnt++;


	// }
	// if(cnt>=mm)
	// 	return 1;
	// else
	// {

	// }
	lli have;
	lli need=k*mm;
	if(n-mm-1>=0)
	have=dp[n-1]-dp[n-mm-1];
else
	 have=dp[n-1];
if(need-have<=n-mm)
	return 1;
else
	return 0;

}