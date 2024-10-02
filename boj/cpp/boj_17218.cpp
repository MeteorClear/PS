// https://www.acmicpc.net/problem/17218

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str1, str2;
    cin >> str1 >> str2;
    
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
    
    for (int i=1; i<=str1.size(); ++i) {
        for (int j=1; j<=str2.size(); ++j) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int y = str1.size(), x = str2.size();
    int now = dp[y][x];
    vector<char> res(dp[y][x]);
    
    while (now > 0) {
        if (dp[y-1][x] == now) {
            --y;
        } else if (dp[y][x-1] == now) {
            --x;
        } else {
            --y;
            --x;
            now = dp[y][x];
            res[now] = str1[y];
        }
    }
    
    for (auto k : res) {
        cout << k;
    }

    return 0;
}
