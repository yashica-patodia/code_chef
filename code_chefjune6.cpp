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

typedef  int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
void solve()
{
	lli a,b,c,p,q,r;
	cin>>a>>b>>c;
	cin>>p>>q>>r;

	int cnt=0;
	if(a==p)
		cnt++;
	if(b==q)
		cnt++;
	if(c==r)
		cnt++;
	if(cnt==3)
	{
		cout<<0<<endl;
		return;
	}
	if(cnt==2)
	{
		cout<<1<<endl;
		return;
	}
	if(cnt==1)
	{
		if(a==p)
		{
			if((q-b==r-c) )
				cout<<1<<endl;
			else if(q>b && r>c)
			{
				if((q/b)==(r/c))
					cout<<1<<endl;
			}
			else
			 cout<<2<<endl;
			return;

		}
		else if(b==q)
		{
			if(p-a==r-c)
				cout<<1<<endl;
			else if(p>a && r>c)
			{
				if((p/a)==(r/c))
					cout<<1<<endl;
			}
			else
			 cout<<2<<endl;
			return;


		}
		else if(c==r)
		{
			if(q-b==p-a)
				cout<<1<<endl;
			else if(q>b && p>a)
			{
				if((q/b)==(p/a))
					cout<<1<<endl;
			}
			else
			 cout<<2<<endl;
			return;

		}

	}

	// else 
	// {
	// 	lli yp=p-a;

	// 	if(yp==(q-b) && yp==(r-c))
	// 	{
	// 		cout<<1<<endl;
	// 		return;
	// 	}
	// 	if(yp==(q-b))

		
	// }
	if(cnt==0)
	{
		if(p>a && q>b && r>c)
		{
		lli d1=p-a;
		lli d2=q-b;
		lli d3=r-c;
		lli dv1=p/a;
		lli dv2=q/b;
		lli dv3=r/c;
		if(d1==d2 && d2==d3)
			cout<<1<<endl;
		else if(dv1==dv2 && dv2==dv3)
			cout<<1<<endl;
		else if((d1==d2 && d2!=d3)  ||(d2==d3 && d1!=d2) ||(d1==d3 && d1!=d2))
			cout<<2<<endl;
		else if((dv1==dv2 && dv2!=dv3)  ||(dv2==dv3 && dv1!=dv2) ||(dv1==dv3 && dv1!=dv2))
			cout<<2<<endl;

		else
		{
			if(d1+d2==d3 || d1+d3==d2 || d2+d3==d1)
				cout<<2<<endl;
			else
				cout<<3<<endl;
		}
		return;
		}
		else
		{
			lli d1=p-a;
			lli d2=q-b;
			lli d3=r-c;
			if(d1==d2 && d2==d3)
			cout<<1<<endl;
		else if((d1==d2 && d2!=d3)  ||(d2==d3 && d1!=d2) ||(d1==d3 && d1!=d2))
			cout<<2<<endl;
		else
		{
			if(d1+d2==d3 || d1+d3==d2 || d2+d3==d1)
				cout<<2<<endl;
			else
				cout<<3<<endl;
		}
		return;

		}
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
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		//cout<<"Case #"<<i<<": ";
		solve();

	}
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
