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
//int n,m;
//vector<pair<pair<lli,lli>,lli>>edgel;

// vector<lli>dis;
// vector<lli>dis2;
// vector<lli>dis3;
//vector<lli>par;
vector<lli> dijs(int src,vector<vector<pair<int,int> >> &adj,int n)
{
	
	// adj.clear();
	// adj.resize(n+1);
	// dis.resize(n+1);
	// dis2.resize(n+1);
	// dis3.resize(n+1);
//	par.resize(n+1);
	vector<lli>dis(n+1);
	for(int i=1;i<=n;i++)
		dis[i]=1e15;
	// for(int i=1;i<=n;i++)
	// 	dis2[i]=1e15;
	// for(int i=1;i<=n;i++)
	// 	dis3[i]=1e15;
	
	priority_queue<pair<lli,int> >pq;
	//vector<bool>vis(n+1,false);
	pq.push({0,src});
	dis[src]=0;
	while(!pq.empty())
	{
		int nn=pq.top().ss;
		// if(vis[nn])
		// 	continue;
		// vis[nn]=true;
		pq.pop();
		for(auto i:adj[nn])
		{
			lli u=i.ff;
			lli w=i.ss;
			if(dis[u]>dis[nn]+w)
			{
				dis[u]=1LL*dis[nn]+w;
				pq.push({-1LL*dis[u],u});
			}
		}
	}
	return dis;
//	lli yp=dis[v];
// 	priority_queue<pair<lli,lli> >pq2;
// 	//mset(vis,false);
// 	vis.assign(n+1,false);
// 	pq2.push({0,v});
// 	dis2[v]=0;
// 	while(!pq2.empty())
// 	{
// 		lli nn=pq2.top().ss;
// 		if(vis[nn])
// 			continue;
// 		vis[nn]=true;
// 		pq2.pop();
// 		for(auto i:adj[nn])
// 		{
// 			lli u=i.ff;
// 			lli w=i.ss;
// 			if(dis2[u]>dis2[nn]+w)
// 			{
// 				dis2[u]=dis2[nn]+w;
// 				pq2.push({-dis2[u],u});
// 			}
// 		}
// 	}
// //	yp+=dis2[tt];

// 	//cout<<yp<<endl;
// priority_queue<pair<lli,lli> >pq3;
// 	//mset(vis,false);
// 	vis.assign(n+1,false);
// 	pq3.push({0,tt});
// 	dis3[tt]=0;
// 	while(!pq3.empty())
// 	{
// 		lli nn=pq3.top().ss;
// 		if(vis[nn])
// 			continue;
// 		vis[nn]=true;
// 		pq3.pop();
// 		for(auto i:adj[nn])
// 		{
// 			lli u=i.ff;
// 			lli w=i.ss;
// 			if(dis3[u]>dis3[nn]+w)
// 			{
// 				dis3[u]=dis3[nn]+w;
// 				pq3.push({-dis3[u],u});
// 			}
// 		}
// 	}
// 	lli yp=1e15;
// 	for(lli i=1;i<=n;i++)
// 	{
// 		yp=min(yp,1LL*dis[i]+dis2[i]+dis3[i]);

// 	}
// 	cout<<yp<<endl;




}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	// clock_t start,end;
	// start=clock();
	int t;
	cin>>t;

	for(int i=1;i<=t;i++)
	{
		int n,m;
		cin>>n>>m;
		int s,tt,v;
		cin>>s>>tt>>v;
		vector<lli> dis1(n+1);
		vector<lli> dis2(n+1);
		vector<lli> dis3(n+1);
		// lli dis2[n+1];
		// lli dis3[n+1];
		vector<vector<pair<int,int> > >adj;
		adj.resize(n+1);
		for(int i=1;i<=m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].pb({b,w});
		adj[b].pb({a,w});
	}

		//cout<<"Case #"<<i<<": ";

		dis1=dijs(s,adj,n);
		dis2=dijs(tt,adj,n);
		dis3=dijs(v,adj,n);
		lli ans=1E16;
		for(int i=1;i<=n;i++)
			ans=min(ans,dis1[i]+dis2[i]+dis3[i]);
		cout<<ans<<endl;


	}
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
