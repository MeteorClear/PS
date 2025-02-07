// https://www.acmicpc.net/problem/1904

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int dp[N+1];
    dp[0] = dp[1] = 1;
    for (int i=2; i<=N; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    
    cout << dp[N];
    
    return 0;
}
