// https://www.acmicpc.net/problem/1197

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
