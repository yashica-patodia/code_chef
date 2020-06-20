#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
lli digit(lli n);

int main()
{
	int t;
	lli a,b,i,index;
	lli mx=0;
	// string a,b;
	int c=0;
	int k;
	cin>>t;
	// vector<int>dig;
	// for(i=0;i<10;i++)
	// 	dig.push_back(i);
	while(t--)
	{
		mx=0;
		c=0;
		cin>>a>>b>>k;
		for(i=a;i<=b;i++)
		{
			// cout<<i<<" ";
			if(i%k!=0)
				continue;
			else
			{
				lli ans=digit(i);
				// cout<<ans<<endl;
				if(ans==0)
					continue;
				else
				{
					if(ans>mx)
					{
						mx=ans;
						index=i;
					}

					
					c++;
					
				}

			}

		}
		if(c==0)
			cout<<-1;
		else
			cout<<mx<<" "<<index<<endl;;


	}
}
lli digit(lli n)
{
lli temp=n;
lli pro=1;
int d1,d2;
while(n>10)
{
	 d1=n%10;
	 d2=n%100;
	if(d1==0 || d2==0)
	{
		return 0;
	}
else	if(d2%d1!=0)
	{
		return 0;

	}
	else
	{
		n=n/10;

	}

}
d1=n%10;
if(d1==0)
return 0;
else
{
if(n%d1==0)
{

	while(temp!=0)
	{
		int d=temp%10;
		pro*=d;
		temp=temp/10;
	}
	// cout<<pro<<endl;
	return pro;
}
else
	return 0;

}
}