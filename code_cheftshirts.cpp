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
long long MOD=1000000007;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))
vector<vector<lli>>people;
lli dp[1030][101];
lli n;
lli recur(lli mask,int num)
{
	
		if(mask==(1LL*(1<<n)-1))
			return 1;
		if(num>100)
			return 0;
	
	if(dp[mask][num]!=-1)
		return dp[mask][num];
	///cout<<num<<" "<<people[num].size()<<endl;
	lli p=recur(mask,num+1);

	for(auto i:people[num])
	{
		if(mask & (1<<i))
			continue;
		//cout<<mask<<" "<<i<<endl;
		p=(p+recur((mask|(1<<i)),num+1))%MOD;
		//cout<<p<<endl;
	}
	return dp[mask][num]=p;
	// if(num==101)
	// {
	// 	if(mask==(1<<n)-1)
	// 		return 1;
	// 	return 0;
	// }
	// lli &ret=dp[mask][num];
	// if(ret!=-1)
	// 	return ret;
	// ret=recur(mask,num+1);
	// for(auto i:people[num])
	// {
	// 	if(mask&(1<<i))
	// 		continue;
	// 	ret+=(recur(mask|(1<<i),num+1));
	// 	ret%=MOD;
	// }
	// return ret;
}
void solve()
{
	people.clear();
	people.resize(101);
	mset(dp,-1);
	cin>>n;
	//cout<<n<<endl;
	string temp,str;
	int x;
	getline(cin,str);
	for(int i=0;i<n;i++)
	{
		//int p;
		getline(cin,str);
		stringstream ss(str);
		while(ss>>temp)
		{
			stringstream s;
			s<<temp;
			s>>x;
			people[x].pb(i);
			//cout<<x<<"yp"<<i<<endl;
		}
	}
	// for(int i=1;i<=100;i++)
	// {
	// 	if(people[i].size()>0)
	// 	{
	// 		cout<<i<<endl;
	// 	for(auto j:people[i])
	// 		cout<<j<<" ";
	// 	cout<<endl;
	// 	}
	// }
	cout<<recur(0,1)<<endl;//0 mask and the first person
	// for(int i=0;i<(1<<n);i++)
	// {
	// 	for(int j=1;j<=100;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }



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
		//cout<<"Case #"<<i<<": ";
		solve();

	}
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
