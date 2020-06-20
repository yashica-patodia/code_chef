#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int m1=0,m2=0;
	int a,b;
	int i;
	while(t--)
	{
		m1=0;
		m2=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a>m1)
				m1=a;
		}
		for(i=0;i<n;i++)
		{
			cin>>b;
			if(b>m2)
				m2=b;
		}
		if(m1==m2)
			cout<<"NO";
		else
			cout<<"YES";
	}
}