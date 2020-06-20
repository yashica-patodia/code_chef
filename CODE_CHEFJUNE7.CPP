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
void solve()
{
	int n,p;
	cin>>n>>p;
	cout<<1<<" "<<1<<" "<<1<<" "<<n<<" "<<n<<endl;
	cout<<flush;
	int tot;
	cin>>tot;
	int mat[n+1][n+1];
	int app=0,f=0,fr,fc;
	for(int i=1;i<=n;i++)
	{
		cout<<1<<" "<<i<<" "<<1<<" "<<i<<" "<<n<<endl;
		cout<<flush;
		int pro;
		cin>>pro;
		int ans=0,ind,f2=0;
		for(int j=1;j<n;j++)
		{
			cout<<1<<" "<<i<<" "<<j<<" "<<i<<" "<<j<<endl;
			cout<<flush;
			cin>>mat[i][j];
			if(mat[i][j])
			{
				ans++;
				app++;
			}
			if(app>=tot)
			{
				f=1;
				fr=i;
				fc=j;
				break;
			}
			if(ans>=pro)
			{
				f2=1;
				ind=j;
				break;
			}


		}
		if(f==1)
			break;
		if(f2==1)
		{
		for(int j=ind+1;j<=n;j++)
			mat[i][j]=0;
		}

		mat[i][n]=pro-ans;
		
		
	}
	if(f==1)
	{
		for(int j=fc+1;j<=n;j++)
			mat[fr][j]=0;
		for(int i=fr+1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				mat[i][j]=0;
		}
	}
	cout<<2<<endl;
	cout<<flush;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
		cout<<flush;
	}
	int yy;
	cin>>yy;
	if(yy==1)
		return;
	if(yy==-1)
		exit(0);

	

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
