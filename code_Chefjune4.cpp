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
	lli ts;
	cin>>ts;
	//lli ans=0;
	// if(ts==1)
	// {
	// 	cout<<0<<endl;
	// 	return ;
	// }
	if(ts%2==1)
	{
		cout<<(1LL*(ts-1))/2<<endl;
		return ;
	}
	else
	{
		if(ts&(ts-1)==0)
		{
			cout<<0<<endl;
			return ;
		}
		lli temp=ts;
		int cnt=0;
		while(temp%2==0)
		{
			temp/=2;
			cnt++;
		}
		// lli t=ts;
		// int cnt2=0;
		// // while(temp2!=0)
		// // {
		// // 	temp2>>=1;
		// // 	cnt2++;
		// // }
		// t--;
		// t|=t>>1;
		// t|=t>>2;
		// t|=t>>4;
		// t|=t>>8;
		// t|=t>>16;
		// t++;
		//cnt2=(int)log2(t);
		lli k=(1*1LL)<<(cnt+1);
		//cout<<k<<" ";
		//lli ans=0;
	//lli p=k;
		cout<<ts/k<<endl;
		//cout<<k<<endl;

		// for(lli i=k+2;i<=ts-2;i+=2)
		// {
		// 	lli j=i;
		// 	lli c=0;
		// 	while(j%2==0)
		// 	{
		// 		j/=2;
		// 		c++;
		// 	}
		// 	if(c>cnt)
		// 	{
		// 		ans+=1;
		// 		cout<<i<<" ";
		// 	}
		// }
	//lli yp;
	// for(lli i=p;i<ts;i+=p)
	// {
	// 	ans++;

	// // }
	// for(lli i=ts-1;i>=1;i--)
	// {
	// 	if(i%p==0)
	// 	{
	// 		yp=i;
	// 		break;

	// 	}
	// }
	// cout<<yp/p<<endl;

		//cout<<ans<<endl;


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
