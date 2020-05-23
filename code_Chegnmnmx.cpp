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
lli fact[5010]={0};
lli inv[5010]={0};
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
void factorial()
{
	lli i;
	fact[0]=1;
	inv[0]=pwr(fact[0],MOD-2);
	for(i=1;i<=5000;i++)
	{
		fact[i]=(i*fact[i-1])%MOD;
		inv[i]=pwr(fact[i],MOD-2);

	}
}
lli findncr(lli x,lli y)
{
	if(x<y)
		return 0;
	if(x<0 || y<0)
		return 0;
	lli temp=fact[x];
	//cout<<temp<<" ";

	temp=(temp*inv[y])%MOD;
	//cout<<temp<<" ";
	temp=(temp*inv[x-y])%MOD;
	//cout<<temp<<endl;
	return temp;
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
	factorial();
	int t;
	cin>>t;
	while(t--)
	{
		lli n,k;
		cin>>n>>k;
		//cout<<n<<k;
		vector<lli>vec(n,0);
		for(lli i=0;i<n;i++)
			cin>>vec[i];
		sort(all(vec));
		vector<lli>min_cnt(n,0);
		lli tot=findncr(n-1,k-1);
		for(lli i=0;i<=n-k;i++)
		{
			min_cnt[i]=findncr(n-(i+1),k-1);
			//cout<<min_cnt[i]<<" ";

		}
		lli pro=1;

		for(int i=0;i<(n/2);i++)
		{
			pro=(pro*(pwr(vec[i]*vec[n-i-1],tot-min_cnt[i]-min_cnt[n-1-i])))%MOD;

		}
		if(n%2==1)
			pro=(pro*(pwr(vec[n/2]*vec[n/2],min_cnt[n/2])))%MOD;
		cout<<pro<<endl;
	}
	// 	end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	


	}