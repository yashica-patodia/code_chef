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
long long int MOD=163577857;
// double startTime;
// double getCurrentTime()
// {
// 	return ((double)clock()-startTime)/CLOCKS_PER_SEC;
// }
lli fact[200001];
lli inv[200001];

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
	for(i=1;i<=200000;i++)
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
	temp=(temp*inv[y])%MOD;
	temp=(temp*inv[x-y])%MOD;
	return temp;
}
// lli inver(lli num)
// {
// 	return pwr(num,MOD-2);
// }
// lli findncr(lli n,lli r)
// {
// 	if(n<r)
// 		return 0;
// 	if(n<0 || r<0)
// 		return 0;
// 	r=min(r,n-r);
// 	if(n==0||n==1||r==0)
// 		return 1;
// 	lli numer=1;
// 	for(lli i=n;i>=n-r+1;i--)
// 		numer=(numer*i)%MOD;
// 	lli den=1;
// 	for(lli i=2;i<=r;i++)
// 		den=(den*i)%MOD;
// 	den=inver(den);
// 	lli res=(numer*den)%MOD;
// 	return res;
// }
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
	factorial();
	// clock_t start,end;
	// start=clock();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>vec(n,0);
		lli cp=0,c=0,cn=0;
		for(int i=0;i<n;i++)
		{
			cin>>vec[i];
			if(vec[i]==1)
				cp++;
			if(vec[i]==-1)
				cn++;
			if(vec[i]==0)
				c++;


		}
		lli sum=pwr(2,c);
		lli temp=0;
		for(lli i=-n;i<=n;i++)
		{
			 temp=(findncr(cp+cn,cp-i)*sum)%MOD;
			if(i==0)
			{
				temp--;
				temp+=MOD;
				temp%=MOD;

			}
			cout<<temp<<" ";
		}
		cout<<endl;


	}
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
