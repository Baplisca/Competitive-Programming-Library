#include <bits/stdc++.h>
using namespace std;

// 問題144 E問題 https://atcoder.jp/contests/abc144/tasks/abc144_e
// 参考URL https://qiita.com/hamko/items/794a92c456164dcc04ad
signed main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    sort(a.rbegin(), a.rend());
    sort(f.begin(), f.end());

    long long ma = 1e12 + 1, mi = -1; // maは右端+1, miは左端-1
    while (ma - mi > 1)
    {
        long long mid = (ma + mi) / 2;
        // midの値以下にできるか
        long long ttl = 0;
        for (int i = 0; i < n; i++)
        {
            long long cnt = mid / f[i]; // 切り捨て
            if (cnt < a[i])
                ttl += a[i] - cnt;
        }
        if (ttl <= k)
            ma = mid;
        else
            mi = mid;
    }
    cout << ma << endl;
}
