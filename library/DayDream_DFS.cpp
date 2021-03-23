#include <iostream>
using namespace std;

string divide[4] = {"dream", "erase", "eraser", "dreamer"};
string S;

bool DFS(int n) { // n文字目以降の文字がうまく切れるかを計算します
    if (n == S.size()) return true; // 最後まできたら成功
    for (string i : divide) {
        if (n + i.size() <= S.size() && S.substr(n, i.size()) == i) {
            if (DFS(n + i.size())) return true; // とりあえず切ってみて成功だったらうれしい
        }
    }
    return false; // どうやっても切れなかったら失敗
}

int main() {
    cin >> S;

    cout << (DFS(0) ? "YES" : "NO") << endl;
}