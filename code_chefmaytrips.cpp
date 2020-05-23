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
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
double startTime;
double getCurrentTime()
{
	return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}

lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x)%MOD;
		x=(x*x)%MOD;
	}
	return res;
}
lli inver(lli num)
{
	return pwr(num,MOD-2);
}
lli findncr(lli n,lli r)
{
	r=min(r,n-r);
	if(n==0||n==1||r==0)
		return 1;
	lli numer=1;
	for(lli i=n;i>=n-r+1;i--)
		numer=(numer*i)%MOD;
	lli den=1;
	for(lli i=2;i<=r;i++)
		den=(den*i)%MOD;
	den=inver(den);
	lli res=(numer*den)%MOD;
	return res;
}
lli gcd(lli a,lli b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	int t;
	cin>>t;
	while(t--)
	{
		lli n,k;
		cin>>n>>k;
		pair<int,int>vec[n+1];
		for(int i=0;i<n;i++)
		{
			lli p;
			cin>>p;
			vec[i].ff=p;
			vec[i].ss=i;
			//cout<<vec[i].ff<<" "<<vec[i].ss<<endl;
		}
		//vector<int>vec2(n+1,0);
		sort(vec,vec+n);
		vector<bool>vis(n+1,false);
		//vector<bool>index;
		psir<int,int>vec2[n+1];

		lli ans=0;
		fr(i,n)
		{
			if(vis[i]|| vec[i].ss==i)
				continue;
			int cyc=0;
			lli j=i;
			//index.pb(j);
			while(!vis[j])
			{
				vis[j]=1;
				j=vec[j].ss;
				//index.pb(j);
				cyc++;
			}
			if(cyc>0)
				ans+=(cyc-1);

		}
		if(k>=ans && (k-ans)%2==0)
		{
			

			cout<<ans<<endl;
			for(int p=1;p<=sz(index);p++)
			{
				if(p%3==0)
					cout<<index[p]+1<<endl;
				else
					cout<<index[p]+1<<" ";

			}
		}
		else
		{
			cout<<-1<<endl;
		}

		

	}
}