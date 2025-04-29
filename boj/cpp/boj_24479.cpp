// https://www.acmicpc.net/problem/24479

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int now, int& cnt) {
    visited[now] = cnt++;
    for (auto next : graph[now]) {
        if (visited[next] != 0) continue;
        dfs(graph, visited, next, cnt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, R, cnt=1;
    cin >> N >> M >> R;
    
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> visited(N + 1);
    
    for (int i=0; i<M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (int i=1; i<=N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(graph, visited, R, cnt);
    
    for (int i=1; i<=N; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}
