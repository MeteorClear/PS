// https://www.acmicpc.net/problem/15681

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int CountChildNode(vector<vector<int>>& tree, vector<int>& child_count, int cur) {
    if (tree[cur].empty()) {
        child_count[cur] = 1;
        return 1;
    }
    int count = 1;
    for (auto next : tree[cur]) {
        count += CountChildNode(tree, child_count, next);
    }
    child_count[cur] = count;
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, R, Q;
    cin >> N >> R >> Q;
    
    vector<vector<int>> graph(N, vector<int>());
    vector<vector<int>> tree(N, vector<int>());
    
    for (int i=1; i<N; ++i) {
        int U, V;
        cin >> U >> V;
        graph[U-1].push_back(V-1);
        graph[V-1].push_back(U-1);
    }
    
    vector<bool> graph_visited(N, false);
    graph_visited[R-1] = true;
    queue<int> q;
    q.push(R-1);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (auto neighbor : graph[current]) {
            if (graph_visited[neighbor]) continue;
            
            graph_visited[neighbor] = true;
            tree[current].push_back(neighbor);
            q.push(neighbor);
        }
    }
    
    vector<int> child_count(N, -1);
    CountChildNode(tree, child_count, R-1);
    
    while (Q--) {
        int U;
        cin >> U;
        cout << child_count[U-1] << '\n';
    }

    return 0;
}
