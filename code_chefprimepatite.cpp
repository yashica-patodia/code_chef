#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define endl '\n'
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
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr<< *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
const lli N=1000010;
lli lpf[N]={0};
void seive()
{
	lpf[1]=1;
	for(lli i=2;i<N;i++)
	{
		if(lpf[i]==0)
		{
			lpf[i]=i;
			for(lli j=2*i;j<N;j+=i)
				if(lpf[j]==0)
					lpf[j]=i;
		}
	}
}
void solve()
{
	lli n;
	cin>>n;
	int q;
	cin>>q;
	//vector<lli>prime;
	//bool pr[n+1];
	vector<bool>pr(n+1,true);
	for(lli i=2;i<=n;i++)
	{
		if(pr[i])
		{
		for(lli j=2*i;j<=n;j+=i)
		{
			//if(pr[j])
				pr[j]=false;
		}
		
		}
	}
	// for(lli i=2;i<=n;i++)
	// {
	// 	if(pr[i])
	// 		cout<<i<<" ";
	// 		//prime.eb(i);
	// }
	lli d=0;
	while(q--)
	{
		lli a,b;
		cin>>a>>b;
		// if(pr[a])
		lli a1=lpf[a];
			lli b1=lpf[b];
		if(a==b)
		{
			d=0;
		}

	else	if(__gcd(a,b)!=1)
		{
			if(pr[a]|| pr[b])
				d=1;
			else
				d=2;

		}
		else if(a==1 || b==1)
			d=-1;
		else if(a1*b1<=n)
		{
			
			if(a1==a && b1==b)
				d=2;
			else if(a1==a || b1==b)
				d=3;
			else
				d=4;
		}
		else if(a1*b1>n)
		{
			if(a1==a && b1==b)
			{
				if(a*2<=n && b*2<=n)
					d=4;
				else d=-1;
			}
			else if(a1==a || b1==b)
			{
				if(a1*2<=n && b1*2<=n)
					d=5;
				else d=-1;
			}
			else 
			{
				if(a1*2<=n && b1*2<=n)
					d=6;
				else
					d=-1;
			}

		}
		cout<<d<<endl;

	}


}
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	// clock_t start,end;
	// start=clock();
	// int t;
	// cin>>t;
	// for(int i=1;i<=t;i++)
	// {
	// 	cout<<"Case #"<<i<<": ";
	// 	solve();

	// }
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	seive();
	solve();
}
