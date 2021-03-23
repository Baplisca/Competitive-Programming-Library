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
    int R,C; cin >> R >> C;
    int s_x,s_y,g_x,g_y;
    cin >> s_x >> s_y >> g_x >> g_y;
    char c[R+2][C+2];
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> c[i][j];
        }
    }
    vector<vector<ll> > dist(R+2,vector<ll>(C+2,MOD));
    dist[s_x][s_y] = 0;
    queue<pair<int,int>> Q;
    Q.push(make_pair(s_x,s_y));

    //幅優先探索
    while(!Q.empty()){
        int cx = Q.front().first, cy = Q.front().second;
        Q.pop();

        //上下左右に動く
        int dy[4] = {1,0,-1,0};
        int dx[4] = {0,1,0,-1};
        for (int i = 0; i < 4; i++) {
            int ex = cx + dx[i], ey = cy + dy[i];
            //行先が壁,もしくは探索済ならやめる
            if (c[ex][ey] != '.' || dist[ex][ey] != MOD) continue;
            Q.push(make_pair(ex, ey));
            dist[ex][ey] = dist[cx][cy] + 1;
        }
    }
    cout << dist[g_x][g_y] << endl;
}
    
