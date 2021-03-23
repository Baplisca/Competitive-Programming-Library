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

typedef tuple<int, int, int, int> T;
signed main()
{   
    gearup;
    int h,w; cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];

    P s,g;
    rep(i,h) rep(j,w) if(c[i][j] == 's') s = make_pair(i,j);
    rep(i,h) rep(j,w) if(c[i][j] == 'g') g = make_pair(i,j);

    vvvl dp(h,vvl(w,vl(3,INF)));
    dp[s.first][s.second][0] = 0;
    priority_queue<T, vector<T>, greater<>> Q; //小さいものから出る
    Q.push(make_tuple(0, s.first, s.second, 0));

    //BFS+DP
    while (!Q.empty()) {
         auto t = Q.top();
         Q.pop();
         int cost = get<0>(t);
         int y = get<1>(t);
         int x = get<2>(t);
         int state = get<3>(t);
         if (cost > dp[y][x][state]) continue; //探索済ならやめる
         for (int i = 0; i < 8; i+=2) {
             int toY = y + dy[i];
             int toX = x + dx[i];
             if (toY < 0 || toY >= h || toX < 0 || toX >= w) continue;
             if (c[toY][toX] == '#') {
                 if (state == 2) continue;
                 if (cost + 1 < dp[toY][toX][state + 1]) {
                     dp[toY][toX][state + 1] = cost + 1;
                     Q.push(make_tuple(cost + 1, toY, toX, state + 1));
                 }
             } else {
                 if (cost + 1 < dp[toY][toX][state]) {
                     dp[toY][toX][state] = cost + 1;
                     Q.push(make_tuple(cost + 1, toY, toX, state));
                 }
             }
         }
     }
     bool res = false;
     rep(i,3) if(dp[g.first][g.second][i] < INF)res = true;
     cout <<(res?"YES":"NO") << endl;
}
