// https://www.acmicpc.net/problem/9655 

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<bool> dp(N + 1, false);
    
    for (int i=2; i<=N; ++i) {
        dp[i] = !dp[i-1];
        if (i > 3) dp[i] = !dp[i-3];
    }
    
    cout << (dp[N] ? "CY" : "SK");

    return 0;
}
