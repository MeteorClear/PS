// https://www.acmicpc.net/problem/6118

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> farm(N+1, vector<int>());
    vector<int> visited(N+1, -1);
    queue<pair<int, int>> q;
    
    while (M--) {
        int A, B;
        cin >> A >> B;
        farm[A].push_back(B);
        farm[B].push_back(A);
    }
    
    q.push({1, 0});
    visited[1] = 0;
    
    while (!q.empty()) {
        auto [barn, dist] = q.front();
        q.pop();
        
        for (int next : farm[barn]) {
            if (visited[next] == -1) {
                q.push({next, dist+1});
                visited[next] = dist+1;
            }
        }
    }
    
    int maxBarn = -1, maxDist = -1, count = 0;
    
    for (int i=1; i<=N; ++i) {
        if (visited[i] > maxDist) {
            maxBarn = i;
            maxDist = visited[i];
            count = 1;
        } else if (visited[i] == maxDist) {
            ++count;
        }
    }
    
    cout << maxBarn << ' ' << maxDist << ' ' << count;

    return 0;
}
