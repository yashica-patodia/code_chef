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
#define all(v) (v).begin, (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
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

typedef vector<plli> vplli;
long long MOD=1000000009;
lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x);
		x=(x*x);
	}
	return res;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	lli mod=998244353;
	//cout<<mod<<" ";
	while(t--)
	{
		
		lli n;
		cin>>n;
		lli a[n];
		map<lli,lli>cnt;
		fr(i,n)
		{
		cin>>a[i];
		cnt[a[i]]++;
		}
		lli pow2[100003];
		pow2[0]=1;
		for(lli i=1;i<=100000;i++)
			pow2[i]=(pow2[i-1]*2)%mod;
		lli cnts=0,ans=0,pro=1,mex=1;
		for(lli i=1;i<=n+1;i++)
		{
			cnts=(cnts+cnt[i])%mod;
			mex=(i*pro)%mod;
			mex=(mex*pow2[n-cnts])%mod;
			ans=(ans+mex)%mod;
			pro=(pro*(pow2[cnt[i]]-1))%mod;

		}
		cout<<ans<<endl;
	}
	}	



		
		


	