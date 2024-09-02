// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> dp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        dp[i] = dp[i-1] + 1;
        if (i%2 == 0) dp[i] = min(dp[i/2]+1, dp[i]);
        if (i%3 == 0) dp[i] = min(dp[i/3]+1, dp[i]);
    }
    
    cout << dp[N];

    return 0;
}
