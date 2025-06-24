// https://www.acmicpc.net/problem/14501

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> dp(N+1, 0);
    for (int i=0; i<N; ++i) {
        int T, P;
        cin >> T >> P;
        
        if (i+T <= N) {
            dp[i+T] = max(dp[i+T], dp[i]+P);
        }
        dp[i+1] = max(dp[i+1], dp[i]);
    }

    cout << dp[N];

    return 0;
}
