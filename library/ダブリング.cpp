#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
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
typedef vector<vector<bool> > vvb;
typedef vector<vector<double> > vvd;
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

//ダブリング 問題167 D https://atcoder.jp/contests/abc167/tasks/abc167_d
signed main()
{   
  gearup;
  ll n,k; cin >> n >> k;
  vl a(n);
  rep(i,n)cin>>a[i],a[i]--; //0-indexed
  int logK = 1;
  while ((1LL << logK) < k) logK++;
  // doubling[k][i] : i番目から 2^k 進んだ町
  vvl doubling(logK,vl(n));
  //前処理計算
  rep(i,n) doubling[0][i] = a[i];
  rep(i,logK-1)rep(j,n) doubling[i + 1][j] = doubling[i][doubling[i][j]]; 

  int now = 0; //最初は0地点
  rep(i,logK){
      if((k >> i) & 1) now = doubling[i][now];
  }
  out(now + 1);
}
