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
	while(t--)
	{
		int n;
		cin>>n;
		lli a[n];
		int f=0;
		fr2(i,n)
		{
			cin>>a[i];
			if(a[i]%n==0 && !f)
			{
				cout<<1<<endl;
				cout<<i+1<<endl;
				f=1;
			}
		}
		if(!f)
		{
		lli pre[n+1];
		pre[0]=0;
		lli cnt[n+1]={0};
		cnt[0]=1;
		int i1,j1;
		inc2(i,1,n)
		{
			pre[i]=(pre[i-1]+a[i-1])%n;
			if(cnt[pre[i]])
			{
					 i1=i;
				break;
			}
			cnt[pre[i]]=1;
		
		}
	
		fr2(j,i1)
		{
			if(pre[j]==pre[i1])
			{
					 j1=j;

				break;
			}

		}
			cout<<i1-j1<<endl;
		for(int p=j1+1;p<=i1;p++)
			cout<<p<<" ";
		cout<<endl;

	}
}
}