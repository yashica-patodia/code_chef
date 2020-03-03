#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	string str;
	// vector<int>vec(n,0);
	int vec[n]={0};
	stack<char>st;

	for(i=0;i<n;i++)
		{
			cin>>str;
			///cout<<str<<endl;
			for(j=0;j<str.length();j++)
				{
					if(str[j]=='<')
					{
						st.push('<');
						//cout<<str[j]<<endl;
					}
					else
					{
						if( !st.empty() && st.top()=='<' )
						{
							vec[i]+=2;
							st.pop();
							//cout<<vec[i]<<endl;
						}


					}
				}
				while(!st.empty())
				{
					//cout<<st.top();
					st.pop();
				}
		}
		for(i=0;i<n;i++)
			cout<<vec[i]<<endl;
}