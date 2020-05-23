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
			res=(res*x)%MOD;
		x=(x*x)%MOD;
	}
	return res;
}
lli inver(lli num)
{
	return pwr(num,MOD-2);
}
lli findncr(lli n,lli r)
{
	r=min(r,n-r);
	if(n==0||n==1||r==0)
		return 1;
	lli numer=1;
	for(lli i=n;i>=n-r+1;i--)
		numer=(numer*i)%MOD;
	lli den=1;
	for(lli i=2;i<=r;i++)
		den=(den*i)%MOD;
	den=inver(den);
	lli res=(numer*den)%MOD;
	return res;
}
lli gcd(lli a,lli b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	cout<<"hell";
	int t;
		//cout<<hell;
		cin>>t;
		cout<<t;
	//cout<<findncr(6,2);
		cout<<MOD;

	lli nr[1001][1001];
	lli f[1001];
	f[0]=1;
	for( lli i=1;i<=1000;i++)
		f[i]=(f[i-1]*i)%MOD;
	for(  lli i=0;i<=1000;i++)
	{
		for(lli j=0;j<=i;j++)
			nr[i][j]=(f[i]*inver(f[j])%MOD*inver(f[i-j])%MOD)%MOD;
	}	
		cout<<"hrll";
		
	// 	while(t--)
	// 	{
	// 		int n;
	// 		cin>>n;
	// 		int a[n];
	// 		fr2(i,n)
	// 		cin>>a[i];
	// 		lli ans=pwr(2,n-1);
	// 		sort(a,a+n);
	// 		for(int i=0;i<n-1;i++)
	// 		{
	// 			for(int j=i+1;j<n;j++)
	// 			{
	// 				if(a[i]==a[j])
	// 					ans=(ans%MOD+ncr[n-2][min(i,n-i-2)]%MOD)%MOD;
	// 				else
	// 					break;
	// 			}
	// 		}
	// 		cout<<ans<<endl;
	// 	}

	//     //clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;
	
	
}
