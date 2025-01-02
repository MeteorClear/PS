// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> tree(n, vector<int>());
    
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    
    vector<int> parent(n, -1);
    parent[0] = 0;
    
    queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (auto next : tree[now]) {
            if (parent[next] != -1) continue;
            parent[next] = now;
            q.push(next);
        }
    }
    
    for (int i=1; i<n; ++i) {
        cout << parent[i]+1 << '\n';
    }

    return 0;
}
