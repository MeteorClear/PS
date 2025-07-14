// https://www.acmicpc.net/problem/11779
// 11779번 최소비용 구하기 2
// 그래프, 다익스트라 문제
// 다익스트라 알고리즘을 이용해 최소비용을 구하고 경로를 추적하여 해결 가능

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    const int INF = 100'000'000;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>({}));
    
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        
        graph[u-1].push_back({v-1, w});
    }
    
    int start, end;
    cin >> start >> end;
    
    vector<int> dist(n, INF);
    dist[start-1] = 0;
    vector<int> path(n, -1);
    path[start-1] = start-1;
    
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq;
    pq.push({0, start-1});
    
    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        
        if (weight > dist[node]) continue;
        
        for (auto [neighbor, neighbor_weight] : graph[node]) {
            if (weight + neighbor_weight < dist[neighbor]) {
                dist[neighbor] = weight + neighbor_weight;
                path[neighbor] = node;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    
    cout << dist[end-1] << '\n';
    
    int now = end-1;
    vector<int> route;
    while (now != start-1) {
        route.push_back(now);
        now = path[now];
    }
    route.push_back(start-1);
    
    cout << route.size() << '\n';
    for (auto it=route.rbegin(); it!=route.rend(); ++it) {
        cout << *it + 1 << ' ';
    }

    return 0;
}
