// https://www.acmicpc.net/problem/14916

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> dp(N+1, 100'000);
    dp[0] = 0;
    
    for (int i=2; i<=N; ++i) {
        if (dp[i-2] != 100'000) dp[i] = min(dp[i], dp[i-2] + 1);
        if (i >= 5 && dp[i-5] != 100'000) dp[i] = min(dp[i], dp[i-5] + 1);
    }
    
    cout << (dp[N] == 100'000 ? -1 : dp[N]);

    return 0;
}
