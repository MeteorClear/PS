// https://www.acmicpc.net/problem/1238
// 1238번 파티
// 그래프, 최단 경로 문제
// 정방향과 역방향 모두 데이크스트라 알고리즘을 적용하여 최단 경로를 구하여 해결 가능

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, X;
    cin >> N >> M >> X;
    
    const int INF = 100'000;
    vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>({}));
    vector<vector<pair<int, int>>> reverse_graph(N, vector<pair<int, int>>({}));
    
    while (M--) {
        int A, B, T;
        cin >> A >> B >> T;
        
        graph[A-1].push_back({B-1, T});
        reverse_graph[B-1].push_back({A-1, T});
    }
    
    vector<int> dist(N, INF);
    dist[X-1] = 0;
    vector<int> reverse_dist(N, INF);
    reverse_dist[X-1] = 0;
    
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq;
                   
    pq.push({0, X-1});
    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        
        if (weight > dist[node]) continue;
        
        for (auto [neighbor, neighbor_weight] : graph[node]) {
            if (weight + neighbor_weight < dist[neighbor]) {
                dist[neighbor] = weight + neighbor_weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    
    pq.push({0, X-1});
    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        
        if (weight > reverse_dist[node]) continue;
        
        for (auto [neighbor, neighbor_weight] : reverse_graph[node]) {
            if (weight + neighbor_weight < reverse_dist[neighbor]) {
                reverse_dist[neighbor] = weight + neighbor_weight;
                pq.push({reverse_dist[neighbor], neighbor});
            }
        }
    }
    
    int res = 0;
    for (int i=0; i<N; ++i) res = max(res, dist[i] + reverse_dist[i]);
    cout << res;

    return 0;
}
