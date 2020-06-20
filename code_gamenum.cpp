#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli decc(int bit[],int ct);
int main()
{
	int t,ct=0;
	lli a,b,ans,mx;
	lli i;
	cin>>t;
	while(t--)
	{
		ct=0;
		mx=0;
		cin>>a>>b;
		lli temp=b;
		lli temp2=b;
		while(temp)
		{
			ct++;
			temp>>=1;
		}
		int  bit[ct+3];
		int j=ct-1;
		while(temp2>0)
		{
			bit[j]=temp2%2;
			temp2/=2;
			j--;
		}
		// for(i=0;i<ct;i++)
		// 	cout<<bit[i];
		int op=0;
		for(i=1;i<ct;i++)
		{
			int	tem=bit[ct-1];
			for( int ii=ct-1;ii>=1;ii--)
			{
				bit[ii]=bit[ii-1];
			}
			bit[0]=tem;	
			b=decc(bit,ct);
			ans=a^b;
			// cout<<ans<<" "<<b<<endl;
			if(ans>mx)
			{
				mx=ans;
				op++;
			}
			// cout<<mx<<" "<<ans<<endl;
		
			// cout<<b<<endl;
		

		}
		cout<<op<<" "<<mx<<endl;
		

	}
}
lli decc(int bit[],int ct)

{
	int i;
	lli n=0;
	lli pw=1;
	for(i=ct-1;i>=0;i--)
	{
		n+=bit[i]*pw;
		// cout<<bit[i]<<" "<<n<<endl;
		pw=pw*2;
	}
	// cout<<n<<endl;
	return n;

}