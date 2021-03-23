#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
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

ll choose(int n, int r) {
    ll acc = 1;
    rep(i,r) acc = acc * (n-i) / (i+1);
    return acc;
}
signed main()
{   
    gearup;
    int n,p; cin >> n >> p;
    ll odd = 0,even =0;
    rep(i,n){
        int m; cin >> m;
        if(m%2==0)even++;
        else odd++;
    }
    ll res = 0;
    if(p==0){ //偶数を取り出す時
        if(even == n)res=(1LL<<even); 
        else{//奇数を偶数個取り出す組み合わせ
            for(int i=p;i<= odd;i+=2){
                res+=choose(odd,i);
            }
            res*=(1LL<<even);
        }
    }
    else{ //奇数を取り出す時
        if(even == n)res = 0;
        else{//奇数を奇数個取り出す組み合わせ
            for(int i=p;i<= odd;i+=2){
                res+=choose(odd,i);
            }
            res*=(1LL<<even);
        }
    }
    cout << res << endl;
}