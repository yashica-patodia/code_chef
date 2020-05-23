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
bool issafe(lli crow,lli ccol,lli prow,lli pcol);
void ways(lli rows,vector<lli> &prev);
void display(vector<lli> &prev);
bool check(int k,int m,int z,lli pre[],int n);

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
int ans=0;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		vector<lli> len;
		fr2(i,n)
		{
			lli f;
		cin>>f;
		len.push_back(f);
	}
		sort(all(len));
		lli pre[n+1];
		pre[0]=0;
		fr2(i,n+1)
		{
			pre[i]=pre[i-1]+len[i-1];
		}

		fr2(i,q)
		{
			int k;
			cin>>k;
			int z=(lower_bound(all(len),k)-len.begin());
			//cout<<z<<" ";
			int ub=n,lb=0,ans=0;
			while(ub>=lb)
			{
				int mm=lb+(ub-lb)/2;
				if(check(k,mm,z,pre,n))
				{
					ans=mm;
					lb=mm+1;
					//cout<<ans<<" ";

				}
				else
					ub=mm-1;
			}
			cout<<ans<<endl;
		}
	}
}
bool check(int k,int m,int z,lli pre[],int n)
{
	int y=n-z;
	int lb=0,ub=z-1,yans=0;
	while(ub>=lb)
	{
		int mm=lb+(ub-lb)/2;
		if((mm+pre[z]-pre[mm])>=((z-mm)*k))
		{
			yans=z-mm;
			ub=mm-1;

		}
		else
			lb=mm+1;
	}

	y+=yans;
	//cout<<y<<" ";
	return (y>=m);

}