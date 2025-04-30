// https://www.acmicpc.net/problem/15990

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int mod = 1'000'000'009;
    vector<vector<long long>> dp(100'001, vector<long long>(4, 0));
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    
    for (int i=4; i<=100'000; ++i) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % mod;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % mod;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % mod;
    }
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << ((dp[n][1] + dp[n][2] + dp[n][3]) % mod) << '\n';
    }

    return 0;
}
