#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
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


vector<int> value; // ノードの値を持つ配列
int N;             // 葉の数

// i (0-indexed) 番目の葉の値を x に変える　
void update(int i, int x) {
    i += N - 1; // i番目は、配列上では N-1+i 番目 (0-indexed)
    value[i] = x;
    while (i > 0) {
        i = (i - 1) / 2; // ノード i の親ノードの番号に変える
        value[i] = min(value[i * 2 + 1],
                       value[i * 2 + 2]); // 左右の子の min を計算しなおす
    }
}
 
// [l,r):value[k]が表している区間 
int query(int a, int b, int k, int l, int r) {
    // [a, b) の区間に対するクエリについて
    // ノード k （区間 [l, r) 担当）が答える
    if (r <= a || b <= l) return INF; // 区間が被らない場合は INF を返す
    if (a <= l && r <= b)
        return value[k]; // ノード k の担当範囲がクエリ区間 [a, b) に完全に含まれる
    else {
        int c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
        int c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
        return min(c1, c2); // 左右の子の値の min を取る
    }
}

// セグ木 設計例　https://www.slideshare.net/iwiwi/ss-3578491
// 問題例 AOJ　RMQ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
signed main()
{   
    gearup;
    int n, q;
    cin >> n >> q;
    N = 1;
    while (N < n) N *= 2; // 葉の数を計算（n以上の最小の2冪数）
 
    value = vector<int>(2 * N - 1, INF); //完全2分木のノードの個数は2n-1 余計なところをINFで初期化

    int m,x,y;
    rep(j,q){
        cin >> m >> x >> y;
        if(m == 1){ //find
             int p = query(x,y+1,0,0,N); //根 (k=0)から l=0, r = Nとして探索
             cout << p << endl;
        }
        else update(x,y); //update
    }
}
