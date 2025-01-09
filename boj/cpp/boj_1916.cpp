// https://www.acmicpc.net/problem/1916

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
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    
    cout << dist[end-1] << '\n';

    return 0;
}
