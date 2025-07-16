// https://www.acmicpc.net/problem/1197
// 1197번 최소 스패닝 트리
// 그래프, 최소 신장 트리, 프림 알고리즘 문제
// 프림 알고리즘을 이용하여 MST를 구하여 해결 가능
// 우선순위 큐를 이용해 가장 가중치가 낮은 간선을 선택
// 모든 정점을 연결할 때까지 방문하지 않은 정점을 추가하면서 최소 비용을 누적

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int V, E;
    cin >> V >> E;
    
    vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>());
    
    while (E--) {
        int A, B, C;
        cin >> A >> B >> C;
        
        graph[A-1].push_back({B-1, C});
        graph[B-1].push_back({A-1, C});
    }
    
    long long res = 0;
    
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    vector<bool> visited(V);
    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        
        if (visited[node]) continue;
        visited[node] = true;
        res += weight;
        
        for (auto [neighbor_node, neighbor_weight] : graph[node]) {
            if (visited[neighbor_node]) continue;
            pq.push({neighbor_weight, neighbor_node});
        }
    }
    
    cout << res;

    return 0;
}
