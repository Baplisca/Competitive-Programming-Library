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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

struct BellmanFordMax {
	BellmanFordMax() {}
	BellmanFordMax(int n) { init(n); }
	vector<vector<pair<int, int> > > E; 
    int N;
	void init(int n) { N = n; E.resize(0); E.clear(); E.resize(n); }
	void add(int a, int b, int c) { E[a].push_back({ b, c }); }
	vector<ll> solve(int s) {
		vector<ll> res(N, -L_INF); //最終的なコスト
		res[s] = 0;
 
        //最長経路を求める (辺に-1をかけると最短経路になる？)
		rep(i, N - 1) {
			rep(cu, N){
                if (-L_INF < res[cu]){
                    for(auto p:E[cu]) {
                        chmax(res[p.first], res[cu] + p.second);
                    }
                }
            }
		}

        //最長経路において正のサイクルの見つける
		vector<bool> pos(N);
		rep(i, N) {
			rep(cu, N) {
                if (-L_INF < res[cu]) {
                    for(auto p:E[cu]) {
                        if (chmax(res[p.first], res[cu] + p.second)) {
                            pos[p.first] = true;
                        }
                        if (pos[cu]) pos[p.first] = true;
                    }
                }
			}
		}
 
		rep(cu, N) if (pos[cu]) res[cu] = L_INF;
 
		return res;
	}
};
//参考 はまやんさんのサイト
//https://www.hamayanhamayan.com/entry/2019/08/14/131217
//問題 ABC137 E https://atcoder.jp/contests/abc137/tasks/abc137_e
signed main()
{   
    gearup;
    int N, M, P; cin >> N >> M >> P;
	BellmanFordMax bf(N);
	rep(i, M) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		bf.add(a, b, c - P);
	}
 
	ll ans = bf.solve(0)[N - 1];
 
	if (ans == L_INF) ans = -1;
	else if (ans < 0) ans = 0;
 
	cout << ans << endl;
}
