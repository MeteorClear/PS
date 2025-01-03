// https://www.acmicpc.net/problem/15681

#include <iostream>
#include <vector>

using namespace std;

int CountChildNode(vector<vector<int>>& graph, 
                   vector<int>& child_count, 
                   int current, int parent) {
    child_count[current] = 1;
    for (auto neighbor : graph[current]) {
        if (neighbor == parent) continue;
        child_count[current] += CountChildNode(graph, child_count, neighbor, current);
    }
    return child_count[current];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, R, Q;
    cin >> N >> R >> Q;
    
    vector<vector<int>> graph(N, vector<int>());
    
    for (int i=1; i<N; ++i) {
        int U, V;
        cin >> U >> V;
        graph[U-1].push_back(V-1);
        graph[V-1].push_back(U-1);
    }
    
    vector<int> child_count(N, -1);
    CountChildNode(graph, child_count, R-1, -1);
    
    while (Q--) {
        int U;
        cin >> U;
        cout << child_count[U-1] << '\n';
    }

    return 0;
}
