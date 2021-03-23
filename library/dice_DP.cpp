#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

//問題URL https://atcoder.jp/contests/tdpc/tasks/tdpc_dice

//サイコロから出る数の素因数は2,3,5
int divisor(ll x, vi &div){
    div.clear();
    div.resize(3);
    while(x % 2 == 0){
        div[0]++;
        x /= 2;
    }
    while(x % 3 == 0){
        div[1]++;
        x /= 3;
    }
    while(x % 5 == 0){
        div[2]++;
        x /= 5;
    }
    return x;
}

signed main()
{   
    gearup;
    ll n,d; cin >> n >> d;
    vi div;
    //dの素因数分解で2,3,5以外が見つかったら確率0
    if(divisor(d,div) != 1){
        cout  << 0.0 << endl;
        return 0;
    }
    vector<vector<vector<vector<double> > > >  dp;
    dp.resize(n+1);
    rep(i,dp.size()){
        dp[i].resize(div[0]+1);
        rep(j,dp[i].size()){
            dp[i][j].resize(div[1]+1);
            rep(k,dp[i][j].size()){
                dp[i][j][k].resize(div[2]+1);
            }
        }
    }

    dp[0][0][0][0] = 1.0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= min(2 * i,div[0]); ++j){
            for(int k = 0; k <= min(i,div[1]); ++k){
                for(int l = 0; l <= min(i,div[2]); ++l) {
                dp[i + 1][j][k][l] += dp[i][j][k][l] / 6;
                dp[i + 1][min(j + 1,div[0])][k][l] += dp[i][j][k][l] / 6;
                dp[i + 1][j][min(k + 1,div[1])][l] += dp[i][j][k][l] / 6;
                dp[i + 1][min(j + 2,div[0])][k][l] += dp[i][j][k][l] / 6;
                dp[i + 1][j][k][min(l + 1,div[2])] += dp[i][j][k][l] / 6;
                dp[i + 1][min(j + 1,div[0])][min(k + 1,div[1])][l] += dp[i][j][k][l] / 6;
                }
            }
        }
    }
    cout << fixed << setprecision(10);
    out(dp[n][div[0]][div[1]][div[2]]);
}
