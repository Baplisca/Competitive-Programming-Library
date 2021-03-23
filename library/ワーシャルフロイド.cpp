#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{   
    //ノード数n,エッジ数m
    ll n,m; cin >> n >> m;
    vector<vector<ll> > dp(n+1,vector<ll>(n+1,INF));
    for(int i=0;i<n;i++){
        dp[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        ll a,b,t; cin >> a >> b >> t;
        a--;b--;
        dp[a][b] = t;
        dp[b][a] = t;
    }

    //ワーシャルフロイド法
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                chmin(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    ll res = INF;
    for(int i=0;i<n;i++){
        ll dist = 0;
        for(int j=0;j<n;j++){
            dist = max(dp[i][j],dist);
        }
        res = min(dist,res);
    }
    cout << res << endl;
}
    