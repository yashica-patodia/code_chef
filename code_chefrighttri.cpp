#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define all(v) (v).begin, (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
#define eps 1e-6
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;

typedef vector<plli> vplli;
long long MOD=1000000009;


double geta(double base,double hyp);
lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x);
		x=(x*x);
	}
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	
	while(t--)
	{
		double h,s;
		cin>>h>>s;
		if(h*h<4*s)
			cout<<-1<<endl;
		else
		{
			double low=0,high=sqrt((h*h)/2.0);
			double base;
			while(abs(high-low)>eps)
			{
				base=(low+high)/2.0;
				if(geta(base,h)>=s)
					high=base;
				else
					low=base;
			}
			//cout<<h<<" ";
			double height=sqrt((h*h)-(base*base));
			if(height>base)
				cout<<fixed<<setprecision(5)<<base<<" "<<height<<" "<<h<<endl;
			else
				cout<<fixed<<setprecision(5)<<height<<" "<<base<<" "<<h<<endl;

		}
	}
}
double geta(double base,double hyp)
{
	double hei=sqrt((hyp*hyp)-(base*base));
	return .5*hei*base;
}