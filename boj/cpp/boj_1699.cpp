// https://www.acmicpc.net/problem/1699
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> dp(N + 1, 100001);
    dp[0] = 0;

    for (int i=1; i<=N; ++i) {
        for (int j=1; j*j<=i; ++j) {
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
