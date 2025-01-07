// https://www.acmicpc.net/problem/1368

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> well_weight(N);
    
    for (int i=0; i<N; ++i) {
        int W;
        cin >> W;
        well_weight[i] = W;
    }
    
    vector<vector<int>> waterway_weight(N, vector<int>(N, 0));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            int P;
            cin >> P;
            waterway_weight[i][j] = P;
        }
    }
    
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    vector<bool> visited(N);
    
    for (int i=0; i<N; ++i) {
        pq.push({well_weight[i], i});
    }
    
    long long res = 0;
    
    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        
        if (visited[node]) continue;
        visited[node] = true;
        
        res += weight;
        for (int neighbor=0; neighbor<N; ++neighbor) {
            int neighbor_weight = waterway_weight[node][neighbor];
            if (neighbor == node || visited[neighbor]) continue;
            
            pq.push({neighbor_weight, neighbor});
        }
    }
    
    cout << res;

    return 0;
}
