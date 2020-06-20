#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,i,j;
	cin>>n>>m;
	int mt[n+1][m+1];

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int f;
			cin>>f;
			mt[i][j]=f;
			
		}
	}
	int dp[n+1][m+1];
	for(i=0;i<n;i++)
		dp[i][0]=mt[i][0];
	for(j=0;j<m;j++)
		dp[0][j]=mt[0][j];
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			// if(mat[i-1][j-1]>=1 && mat[i-1][j]>=1 && mat[i][j-1]>=1)
			// 	dp[i][j]=2;
			int m1=max(mt[i-1][j-1],mt[i-1][j]);
			int m2=max(mt[i][j-1],m1);
			//)
			// 	dp
			int a=mt[i-1][j-1];
			int b=mt[i-1][j];
			int c=mt[i][j-1];
			if(a==b && b==c)
				dp[i][j]=m2+1;
			else 
				dp[i][j]=m2;

		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	// int t;
	// int x1,y1,x2,y2;
	// cin>>t;
	// while(t--)
	// {
	// 	cin>>x1>>y1>>x2>>y2;



	// }

}

