// https://www.acmicpc.net/problem/2644

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, start, end, m;
    cin >> n >> start >> end >> m;
    
    vector<vector<int>> family(n+1, vector<int>());
    vector<int> visited(n+1, -1);
    queue<int> q;
    
    for (int i=0; i<m; ++i) {
        int x, y;
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }
    
    q.push(start);
    visited[start] = 0;
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        if (now == end) break;
        
        for (auto next : family[now]) {
            if (visited[next] >= 0) continue;
            q.push(next);
            visited[next] = visited[now] + 1;
        }
    }
    
    cout << visited[end];

    return 0;
}
