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
typedef vector<vlli> matrix;
long long MOD=1000000007;
matrix matrixUnit(lli n) {
    matrix res(n, vlli(n));
    for (lli i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}
 
matrix matrixAdd(const matrix &a, const matrix &b) {
    lli n = a.size();
    lli m = a[0].size();
    matrix res(n, vlli(m));
    for (lli i = 0; i < n; i++)
        for (lli j = 0; j < m; j++)
            res[i][j] = (a[i][j] + b[i][j]) % MOD;
    return res;
}
 
matrix matrixMul(const matrix &a, const matrix &b) {
    lli n = a.size();
    lli m = a[0].size();
    lli k = b[0].size();
    matrix res(n, vlli(k));
    for (lli i = 0; i < n; i++)
        for (lli j = 0; j < k; j++)
            for (lli p = 0; p < m; p++)
                res[i][j] = (res[i][j] + (long long int) a[i][p] * b[p][j]) % MOD;
    return res;
}
 
matrix matrixPow(const matrix &a, lli p) {
    if (p == 0)
        return matrixUnit(a.size());
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}
 
matrix matrixPowSum(const matrix &a, lli p) {
    lli n = a.size();
    if (p == 0)
        return matrix(n, vlli(n));
    if (p % 2 == 0)
        return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n), matrixPow(a, p / 2)));
    return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
}
//create new matrix as a(#rows,vlli(#cols))
int main()
{

    //     #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    IOS
    // clock_t start,end;
    // start=clock();
    int t;
    cin>>t;
    matrix dp(4,vlli(4));
   // dp[4][4]={36,36,36,36,1,0,0,0,0,36,36,0,0,0,36,0};
    for(lli i=0;i<4;i++)
        dp[0][i]=36;
    for(lli i=0;i<4;i++)
    {
        if(i==0)
        dp[1][i]=1;
    else
        dp[1][i]=0;
    }
    dp[2][0]=dp[2][3]=0;
    dp[2][1]=dp[2][2]=36;
    for(lli i=0;i<4;i++)
    {
        if(i==2)
        dp[3][i]=36;
    else
        dp[3][i]=0;
    }

    matrix b(4,vlli(1));
   // b[4][1]={{108},{36},{36},{1}};
    b[0][0]=108;
    b[1][0]=b[2][0]=36;
    b[3][0]=1;
    while(t--)
    {
        lli n;
        cin>>n;
        if(n==0)
        {
            cout<<1<<endl;
            continue;

        }
        if(n==1)
        {
            cout<<108<<endl;
            continue;
        }
        dp=matrixPow(dp,n-1);
        matrix ans(4,vlli(1));
        ans=matrixMul(dp,b);
        cout<<ans[0][0]%MOD<<endl;
        

    }
}