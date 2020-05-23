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
int add(int a,int b)
{
	int res=a+b;
	if(res>=MOD)
		return res-MOD;
	return res;

}
lli  mult(int a,int b)
{
	lli res=a;
	res*=b;
	if(res>=MOD)
		return res%MOD;
	return res;

}
const int n=4;
struct matrix
{
	int arr[n][n];
	void reset()
	{
		memset(arr,0,sizeof(arr));
	}
	void makeiden()
	{
		reset();
		for(int i=0;i<n;i++)
			arr[i][i]=1;
	}
	matrix operator +(const matrix &o) const
	{
		matrix res;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				res.arr[i][j]=add(arr[i][j],o.arr[i][j]);
		}
		return res;
	}
	matrix operator *(const matrix &o) const
	{
		matrix res;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				res.arr[i][j]=0;
				for(int k=0;k<n;k++)
				{
					res.arr[i][j]=add(res.arr[i][j],mult(arr[i][k],o.arr[k][j]));
				}
			}
		}
		return res;
	}

};
matrix power(matrix a,lli b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b&1)
			res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
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
	matrix dp;
	for(int i=0;i<4;i++)
	{
		dp.arr[0][i]=36;
		

	}
	for(int i=0;i<4;i++)
		if(i==3)
		dp.arr[3][i]=1;
	else
		dp.arr[3][i]=0;
	for(int i=0;i<4;i++)
		if(i==2)
			dp.arr[2][i]=36;
		else
			dp.arr[2][i]=0;
		dp.arr[1][0]=dp.arr[1][3]=0;
		dp.arr[1][1]=dp.arr[1][2]=36;

		matrix B;
		B.arr[0][0]=108;
		B.arr[1][0]=36;
		B.arr[2][0]=36;
		B.arr[3][0]=1;
		for(int i=0;i<4;i++)
		{
			for(int j=1;j<4;j++)
				B.arr[i][j]=0;
		}
	
	while(t--)
	{
	lli n1;
	cin>>n1;
	if(n1==0)
	{
		cout<<1<<endl;
		continue;
	}
	if(n1==1)
	{
		cout<<108<<endl;
		continue;
	}
	matrix expo=power(dp,n1-1);
	matrix ans=expo*B;
	lli sum=ans.arr[0][0];
	cout<<sum<<endl;




	}
	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<time_taken<<setprecision(5)<<" sec"<<endl;
	
}
