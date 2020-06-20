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
lli n,m,k,s;
lli p[11][11];
//vector<pair<pair<lli,lli>,pair<lli,lli> >edgel;

vector<pair<pair<lli,lli>,lli>>adj[100100];
lli dis[100100][11];
void solve()
{
	cin>>n>>m>>k>>s;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
			cin>>p[i][j];
	}
	//edgel.resize(m+1);
	//adj.resize(n+1);
	//dis.resize(n+1);
	for(int i=1;i<=m;i++)
	{
		lli u,v,c,t;
		cin>>u>>v>>c>>t;
		adj[u].pb({{v,c},t});
		adj[v].pb({{u,c},t});

		//edgel[i]={{u,v},{c,t}};
	}
	//for k=1 just add p[1][1]to c
	//lli yp=p[1][1];
	for(lli i=0;i<=n;i++)
	{
		for(lli j=0;j<=k;j++)
		dis[i][j]=MOD;
	}
	for(int i=0;i<=k;i++)
		dis[s][i]=0;
	priority_queue<pair<pair<lli,lli>,lli> >pq;
	pq.push({{0,s},0});
	
	while(!pq.empty())
	{
		lli u=pq.top().ff.ss;
		lli cost=-pq.top().ff.ff;
		lli t=pq.top().ss;
		pq.pop();
		for(auto j:adj[u])
		{
			lli v=j.ff.ff;
			lli yp=j.ff.ss;
			lli tt=j.ss;
			lli yp2=cost+yp;
			if(t!=0)
				yp2+=p[t][tt];//JUST TJIS PAART IS EXTRA ELSE EVERYTHING IS SAMW
			if(dis[v][tt]>yp2)
			{
				dis[v][tt]=yp2;
				pq.push({{-yp2,v},tt});
			}


		}
	}
	for(int i=1;i<=n;i++)
	{
		lli ans=MOD;
		for(int j=1;j<=k;j++)
			ans=min(ans,dis[i][j]);
		if(ans!=MOD)
			cout<<ans<<" ";
		else
			cout<<-1<<" ";

	}



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
	solve();
	
}
