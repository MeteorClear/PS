// https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int V, E, K;
    cin >> V >> E >> K;
    
    const int INF = 3'000'000;
    vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>({}));
    
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        
        graph[u-1].push_back({v-1, w});
    }
    
    vector<int> dist(V, INF);
    dist[K-1] = 0;
    
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq;
    pq.push({0, K-1});
    
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
    
    for (auto e : dist) {
        if (e == INF) {
            cout << "INF\n";
            continue;
        }
        cout << e << '\n';
    }

    return 0;
}
