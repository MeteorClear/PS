// https://www.acmicpc.net/problem/9658

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<bool> dp(N + 1, false);
    
    for (int i=1; i<=N; ++i) {
        bool win = false;
        if (i>=1 && !dp[i-1]) win = true;
        if (i>=3 && !dp[i-3]) win = true;
        if (i>=4 && !dp[i-4]) win = true;
        dp[i] = win;
    }
    
    cout << (dp[N-1] ? "SK" : "CY");

    return 0;
}
