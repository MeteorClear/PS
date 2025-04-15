// https://www.acmicpc.net/problem/2193
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long dp[91] = {1, 1,};
    int N;
    cin >> N;
    for (int i=2; i<N; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N-1];

    return 0;
}
