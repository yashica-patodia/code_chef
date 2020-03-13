#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli gcd(int a,int b);

int main()
{
	lli t,a,b,i;
	cin>>t;
	vector<lli>vec;
	vector<lli>vec2;
	for(i=0;i<t;i++)
	{
		cin>>a>>b;
		lli k=gcd(a,b);
		vec.push_back(k);
		vec2.push_back((a*b)/k);

	}
	for(i=0;i<vec.size();i++)
		cout<<vec[i]<<" "<<vec2[i]<<endl;
}

lli gcd(int a,int b)
{
	if(b==0)
		return a;
	return  gcd(b,a%b);
}