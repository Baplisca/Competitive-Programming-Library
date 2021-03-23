#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)
const int INF = 1LL<<30;

int a[100001],dp[100001];
int main()
{   
    int n; cin >> n;
    rep(i,n)cin>>a[i];
    rep(i,n)dp[i] = INF;
    rep(i,n){
        int pos = lower_bound(dp, dp+n, a[i]) - dp;
        dp[pos] = a[i];
    }
    int cnt = lower_bound(dp, dp+n, INF) - dp;
    cout << cnt << endl;

    return 0;
}
