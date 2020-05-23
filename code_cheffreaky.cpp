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
void solve()
{
	int n;
	cin>>n;
	map<int,vector<pair<int,lli>> >adj;
	priority_queue<pair<lli,int>> pq;
	vector<lli>dis(n+1,MOD);
	lli sum=0;
	fr2(i,n-1)
	{
		int x,y;
		lli w;
		cin>>x>>y>>w;
		sum+=w;
		adj[x].eb(make_pair(y,w));
		adj[y].eb(make_pair(x,w));
		//pq.push(make_pair(-w,y));

	}
	pq.push(make_pair(0,1));
	dis[1]=0;
	while(!pq.empty())
	{
		pair<lli,int> p=pq.top();
		int vert=p.ss;
		pq.pop();
		for(auto j=adj[vert].begin();j!=adj[vert].end();j++)

		{
			int v=(*j).ff;
			lli wei=(*j).ss;
			if(dis[v]>dis[vert]+wei)
			{
				dis[v]=dis[vert]+wei;
				pq.push(make_pair(-dis[v],v));
			}

		}

	}
	lli as=dis[1];
	fr2(i,n)
	{
		as=max(as,dis[i+1]);
	}
	//fr2(i,n)
	cout<<2*sum-as<<endl;

}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	clock_t start,end;
	start=clock();
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		//cout<<"Case #"<<i<<": ";
		solve();

	}
	//solve();

	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
