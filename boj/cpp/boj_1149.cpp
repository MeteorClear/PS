// https://www.acmicpc.net/problem/1149
// 1149번 RGB거리
// 다이나믹 프로그래밍 문제
// 다차원 dp 테이블을 만들어 해결 가능
// dp[i][c] = i번째 집을 색상 c(0:빨강, 1:초록, 2:파랑)으로 칠할 때의 최소 비용
// dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0] (빨강)
// dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1] (초록)
// dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2] (파랑)
// 최종 결과 min(dp[N-1][0], dp[N-1][1], dp[N-1][2])

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<vector<int>> rgb(N, vector<int>(3));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<3; ++j) {
            cin >> rgb[i][j];
        }
    }
    
    vector<vector<int>> dp(N, vector<int>(3));
    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];
    
    for (int i=1; i<N; ++i) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
    }
    
    cout << min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});

    return 0;
}
