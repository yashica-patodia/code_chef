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
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
double startTime;
double getCurrentTime()
{
	return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}

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
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		string str;
		cin>>str;
		map<int,int>mp;
		for(int i=0;i<sz(str);i++)
			mp[str[i]-97]++;
		//priority_queue<int>pq;
		//for(auto j:mp)
			//cout<<mp.ff<<" "<<mp.ss<<" ";
			//cout<<mp[j]<<" ";
			//cout<<j->ff<<" "<<j->ss<<" ";
		map<int,int>:: iterator it;
		map<int,int>mp2;

		for(it=mp.begin();it!=mp.end();it++)
		{
			mp2[it->ss]++;
			//cout<<it->ff<<" "<<it->ss<<endl;
		}
		map<int,int>:: iterator it2;
		it2=mp2.end();
		--it2;
		lli k=it2->ff;
		// map<int,int>:: iterator it4;
		// for(it4=mp2.begin();it4!=mp2.end();it4++)
		// {
		// 	//mp2[it->ss]++;
		// 	cout<<it4->ff<<" "<<it4->ss<<endl;
		// }
		//cout<<k<<endl;

		// cout<<sz(mp)<<endl;
		//set<int>st;
		//map<int,int>:: iterator it5;
// vector<lli>tot(k+1,0);
// 			 	for(int i=k;i>=1;i--)
// 			 	{
// 			 		if(i==k)
// 			 		tot[i]=mp2[i];
// 			 	else
// 			 	{
// 			 		if(mp2.find(i)!=mp2.end())
// 			 		tot[i]=tot[i+1]+mp2[i];
// 			 	else
// 			 		tot[i]=tot[i+1];

// 			 	}

// 			 	}
			 	// for(int i=1;i<=k;i++)
			 	// cout<<tot[i]<<" ";

		while(q--)
		{
			lli c;
			cin>>c;
			if(c>=k)
			 //lli ans=min(c,sz(mp));
			 
			 {
			 	cout<<0<<endl;
			 	continue;
			 }
			 if(c==0)
			 {
			 	cout<<sz(str)<<endl;
			 	continue;
			 }
		// 	 priority_queue<int>pq;

		// for(int i=0;i<26;i++)
		// {
		// 	if(mp[i]!=0)
		// 	pq.push(mp[i]);

		// }
		// 	 lli sum=0;
		// 	 while( !pq.empty() && ans!=0)
		// 	 {
		// 	 	sum+=pq.top();
		// 	 	pq.pop();
		// 	 	ans--;

		// 	 }
		// 	 lli ans2=sz(str)-sum;
		// 	 cout<<ans2<<endl;
			 else
			 {
			 	

			 	// lli sum=sz(str);
			 	// map<int,int>::iterator it3;
			 	// //it3=mp2.begin();
			 	// for(it3=mp2.begin();it3!=mp2.end();it3++)
			 	// {
			 	// 	if(it3->ff<=c)
			 	// 	{
			 	// 		sum-=((it3->ss)*(it3->ff))
			 	// 	}
			 	// 	else
			 	// 		break;

			 	// }
			 	lli ans=0;
			 	map<int,int>:: iterator it6 ;
			 	for(it6=mp.begin();it6!=mp.end();it6++)
			 		ans+=max((lli)0,(it6->ss)-c);



			 	// lli sum=0;
			 	// sum=sz(str)-tot[c];
			 	cout<<ans<<endl;

			 }

		}
	}
}