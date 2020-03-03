#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	string str,str1,ans;
	cin>>n>>str;
	map<char,char>mp;
	map<int,string>mp2;
	for(i=0;i<str.length();i++)
	{
		mp[char(97+i)]=str[i];

	}
	mp['.']='.';
	mp[',']=',';
	mp['!']='!';
	mp['?']='?';
	for(i=0;i<n;i++)
	{
		cin>>str1;
		for(j=0;j<str1.length();j++)
		{
			// cout<<str1[j]<<endl;
			if(isalpha(str1[j]))
			{
				if(isupper(str1[j]))
				ans+=mp[str1[j]+32]-32;
			else
				ans+=mp[str1[j]];
			}
			else if(str1[j]=='_')

			{
				ans+=" ";


			}
			else
			{
				// cout<<str1[j]<<endl;
				// ans+=mp[str1[j]];
				ans+=str1[j];
			}

		}
		cout<<ans<<endl;
		mp2[i]=ans;
		ans="";

	}
	// for(i=0;i<n;i++)
	// {
	// 	cout<<mp[i]<<endl;
	// }

}