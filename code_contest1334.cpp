#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,x,y,i;
	cin>>t;
	while(t--)
	{
		int f=1;
		cin>>n;
		vector<pair<int,int> >vec;
		for(i=0;i<n;i++)
		{
			cin>>x>>y;
			vec.push_back(make_pair(x,y) );
			//cout<<vec[i].first<<" "<<vec[i].second<<endl;
		}
		// for(i=0;i<n;i++)
		// {
			
		// 	cout<<vec[i].first<<" "<<vec[i].second<<endl;
		// }


		string ans;
		if(vec[0].first<vec[0].second)
			ans="NO";
		else
		{
			for(i=1;i<n;i++)
			{
				if(vec[i].first<vec[i].second)
				{
					f=0;
					break;
				}
				if(vec[i].second>vec[i-1].second)
				{
					if(vec[i].first<=vec[i-1].first)
					{
						f=0;
						break;
					}
				}
				if(vec[i].first<vec[i-1].first)
				{
					f=0;
					break;
				}
				if(vec[i].second<vec[i-1].second)
				{
					f=0;
					break;
				}
				if(vec[i].first-vec[i-1].first <vec[i].second-vec[i-1].second)
				{
					f=0;
					break;
				}

			}
			if(f==1)
				ans="YES";
			else
				ans="NO";
		}
		cout<<ans;
		cout<<endl;

	}
}