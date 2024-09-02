// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int stairs;
    cin >> stairs;
    
    vector<int> s(stairs);
    
    for (int i=0; i<stairs; ++i) {
        cin >> s[i];
    }
    
    if (stairs == 1) {
        cout << s[0];
        return 0;
    }
    
    if (stairs == 2) {
        cout << s[0] + s[1];
        return 0;
    }
    
    vector<vector<int>> dp(stairs, vector<int>(2, 0));
    
    dp[0][0] = s[0]; dp[0][1] = 0;
    dp[1][0] = s[1]; dp[1][1] = s[0] + s[1];
    
    for (int i=2; i<stairs; ++i) {
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + s[i];
        dp[i][1] = dp[i-1][0] + s[i];
    }
    
    cout << max(dp[stairs-1][0], dp[stairs-1][1]);

    return 0;
}
