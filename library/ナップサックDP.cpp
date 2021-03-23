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
    int n,w; cin >> n >> w;
    //最大化DPのため初期化
    vector<vector<ll> > dp(w+1,vector<ll>(n+1,0));
    vector<ll> weight(n+1,0);
    vector<ll> value(n+1,0);

    for(int i=0;i<n;i++) cin >> weight[i] >> value[i];

    for(int i=0;i <= w;i++){
        for(int j=0;j<n;j++){

            //iの重さより小さくて、w以下であれば
            if(i - weight[j] >= 0)
                chmax(dp[i][j+1],dp[i-weight[j]][j] + value[j]);

            chmax(dp[i][j+1],dp[i][j]);
        }

    }
    cout << dp[w][n] << endl;
}
    