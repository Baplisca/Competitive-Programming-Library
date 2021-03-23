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

void print(vector<vector<char> > c){
    rep(i,8) {
        rep(j,8){
        cout << c[i][j];
        }
        cout << endl;
    }
}
bool check(vector<int> a,vector<vector<char> > c){
    vector<vector<char> > s(8,vector<char>(8,'.'));
    rep(i,8) s[i][a[i]] = 'Q';
    //3地点を含んでいるか
    rep(i,8){
        rep(j,8){
            if(c[i][j] == 'Q')
                if(s[i][j] != 'Q')return false;
        }
    }
    //print(s);
    //斜めを探索してQが一つだけか
    rep(i,8){
        rep(j,8){
            if(s[i][j] == 'Q') {
                rep(dir, 8) {
                    // (x,y)は現在のマス
                    ll x = i;
                    ll y = j;
                    while(1) {
                        x += dx[dir];
                        y += dy[dir];
                        if(x < 0 || 8 <= x || y < 0 || 8 <= y) break;
                        if(s[x][y] == 'Q') return false; // (x,y)にクイーンがあるとダメ
                    }
                }
            }
        }
    }
    print(s);
    return true;
}
signed main()
{   
    gearup;
    vector<vector<char> > c(8,vector<char>(8));
    rep(i,8) rep(j,8) cin >> c[i][j];
    vector<int> a(8);
    bool res = false;
    rep(i,8) a[i] = i;
    do{
        if(check(a,c)){
            res = true;
             break;
        }
    }while(next_permutation(all(a)));
    if(!res) cout << "No Answer" << endl;
}