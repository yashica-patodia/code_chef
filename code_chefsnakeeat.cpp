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
bool issafe(lli crow,lli ccol,lli prow,lli pcol);
void ways(lli rows,vector<lli> &prev);
void display(vector<lli> &prev);

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
//lli ans=0;
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
		int len[n+1];
		fr2(i,n)
		cin>>len[i];
		sort(len,len+n);
		
		fr2(i,q)
		{
			int k;
			cin>>k;
			int diff[n+1];
			int temp=k;
			diff[n]=0;
			dec2(j,n-1,0)
			{
				diff[j]=diff[j+1]+max(0,k-len[j]);
				

			}
			int cnt=0;
			int b=0;
			int j;
			for(j=n-1;j>=0 && j>=b;j--)
			{
				if(diff[j]==0)
					cnt++;
				else
				{
					if(diff[j]>(j-b))
						break;
					else
					{
						b+=diff[j];
						cnt++;

					}

				}
			}
			cout<<cnt<<endl;
		}
	}
}