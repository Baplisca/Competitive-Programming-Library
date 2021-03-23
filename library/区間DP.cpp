#include <bits/stdc++.h>
using namespace std;

//区間DP http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=ja
signed main()
{   
  while(1){
    int n; cin >> n;
    if(n == 0)break;
    vector<int> w(n);
    for(int i=0;i<n;i++)cin>>w[i];
    vector<vector<int> > dp(n+1,vector<int>(n+1,-1)); //dp[l][r] 区間[l,r)で最大の取り除ける数
    for(int W = 2;W<=n;W++){
      for(int l = 0;l<n;l++){
        int r = l + W;
        if(r > n)continue;
        //全部取り除けるとき
        if(dp[l+1][r-1] == W - 2 && abs(w[l] - w[r-1]) <= 1) dp[l][r] = max(dp[l][r], W);
        else for(int mid = l;mid <= r;mid++)dp[l][r] = max(dp[l][r], dp[l][mid]+dp[mid][r]);
      }
    }
    cout << dp[0][n] << endl;
  }
  return 0;
}
