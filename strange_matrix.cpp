#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,p,i,j,q,iv,jv;
	cin>>n>>m>>p;

	// vector<vector<int> >mt(n,vector<int>(m,0));
	 // vector< vector< int> >mt;
	int mt[n][m]={0};
	// vector<int>vec;
	int vec[n]={0};
	
	for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				{
					mt[i][j]=j+1;

				}
		}

	// for(i=0;i<n;i++)
	// 	{
	// 		for(j=0;j<m;j++)
	// 			{
	// 				cout<<mt[i][j]<<" ";
	// 			}
	// 			cout<<endl;
	// 	}
		for(q=0;q<p;q++)
	    {
		cin>>iv>>jv;
		mt[iv-1][jv-1]+=1;
		}
		// for(i=0;i<n;i++)
		// {
		// 	for(j=0;j<m;j++)
		// 		{
		// 			cout<<mt[i][j]<<" ";
		// 		}
		// 		cout<<endl;
		// }

		for(i=0;i<n;i++)
			{
				for(j=m-1;j>=1;j--)
					{
						if(mt[i][j]>=mt[i][j-1])
							vec[i]+=mt[i][j]-mt[i][j-1];
						else
						{
							vec[i]=-1;
							break;
						}


					}
			}
			for(i=0;i<n;i++)
				cout<<vec[i]<<endl;

}