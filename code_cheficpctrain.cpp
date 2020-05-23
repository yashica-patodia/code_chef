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
 struct node
{
	
	int di;
	int ti;
	int si;

bool operator<(const node &a) const
{
	return si<a.si;
}

};





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
		int n,d;
		cin>>n>>d;
		priority_queue<node> pq;
		priority_queue<node>();
		fr2(i,n)
		{
			node a;
			cin>>a.di>>a.ti>>a.si;
			pq.push(a);
		}
			// while(!pq.empty())
			// {
			// 	node x=pq.top();
			// 	cout<<x.di<<" "<<x.ti<<" "<<x.si<<endl;
			// 	pq.pop();

			// }
		 vector<bool> days(d,false);
		//mset(days,0);
		lli sum=0;
		while(!pq.empty())
		{
			node x=pq.top();
			pq.pop();
		
		for(int i=x.di;i<=d && x.ti>0;i++)
		{
			if(days[i]==0)
			{
				days[i]=1;
				x.ti--;
			}

		}
		sum+=(x.ti)*(x.si);

		}
		cout<<sum<<endl;



	}
	
}
