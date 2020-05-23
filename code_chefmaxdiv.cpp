#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using vi=vector<lli>;
using ii=pair<lli,lli>;
using vii=vector<ii>;
using ld=long double;
void solve(){
	lli n,k;cin>>n>>k;
	map<lli,lli> mp;
	for(int i=0;i<n;i++){
		lli x;cin>>x;
		mp[x]++;
	}
	multiset<lli> st;
	for(auto v:mp){
		if(v.second>1)st.insert(v.second);
	}
	while(k&&!st.empty()){
		auto it=st.end();it--;
		lli val=*it;st.erase(it);
		val--;
		if(val>1){
			st.insert(val);
		}
		k--;
	}
	lli ans=n*(n-1)/2;
	for(auto v:st){
		ans=ans-v*(v-1)/2;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t=1;cin>>_t;
	for(int _i=1;_i<=_t;_i++){
		solve();
	}
}