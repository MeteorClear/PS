// https://www.acmicpc.net/problem/13549
// 13549번 숨바꼭질 3
// 그래프, 최단 경로, 데이크스트라 문제
// 수빈이의 이동조건을 기반으로 데이크스트라 알고리즘을 적용해 해결 가능

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(100001, -1);
    
    pq.push({0, N});
    visited[N] = 0;
    
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        
        if (cur.second == K) {
            cout << cur.first;
            break;
        }
        
        int next[3] = {cur.second*2, cur.second+1, cur.second-1};
        int weight[3] = {0, 1, 1};
        
        for (int dir=0; dir<3; ++dir) {
            if (next[dir] < 0 || next[dir] >= 100001) continue;
            if (visited[next[dir]] == -1 || visited[next[dir]] > cur.first + weight[dir]) {
                visited[next[dir]] = cur.first + weight[dir];
                pq.push({cur.first + weight[dir], next[dir]});
            }
        }
    }

    return 0;
}
