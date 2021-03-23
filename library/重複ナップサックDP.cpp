#include <iostream>
#include <vector>
const int inf = 1e9;
int main(){
    std::vector<int> chocolates = {6, 4, 5, 6};
    int max_seats = 38;
    int c1 = 1;
    int c2 = c1 * max_seats;
    int c3 = c2 * max_seats;
    int c4 = c3 * max_seats;
    std::vector<int> w = {
        c1 + c2 + c3 + c4,
        c1 + c2 + c3     ,
             c2 + c3 + c4,
        c1 + c2          ,
                  c3 + c4,
        c1           + c4,
             c2 + c3     ,
        c1      + c3     ,
             c2      + c4,
        c1               ,
             c2          ,
                  c3     ,
                       c4
    };
    //重複ナップサックDP
    int dp_h = 14, dp_w = c4 * max_seats + 1;
    std::vector<std::vector<int>> dp(dp_h, std::vector<int>(dp_w, inf));
    dp[0][0] = 0;
    for(int i = 1; i < dp_h; i++){
        for(int j = 0; j < dp_w; j++){
            if(dp[i - 1][j] < dp[i][j]) dp[i][j] = dp[i - 1][j];
            if(0 <= j - w[i - 1]){
                if((dp[i][j - w[i - 1]] + 1) < dp[i][j])
                    dp[i][j] = dp[i][j - w[i - 1]] + 1;
            }
        }
    }
    //DP復元
    int condition = chocolates[0] * c1 + chocolates[1] * c2 + chocolates[2] * c3 + chocolates[3] * c4;
    std::vector<int> choice(13, 0);
    int nh = dp_h - 1, nw = condition;
    while(1 < nh || 0 < nw){
        if (nh == 1 || (0 <= nw - w[nh - 1] && dp[nh][nw - w[nh - 1]] + 1 == dp[nh][nw])){
            choice[nh - 1]++;
            nw -= w[nh - 1];
        }else{
            nh--;
        }
    }

    //解の出力
    std::cout << dp[dp_h - 1][condition] << "RT"<< std::endl;
    for(int i = 0; i < 13; i++){
        if(!choice[i]) continue;
        std::cout << "chocolates box " << i + 1 << " : " << choice[i] <<  std::endl;
    }
    return 0;
}