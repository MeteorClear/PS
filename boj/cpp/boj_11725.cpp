// https://www.acmicpc.net/problem/11725
// 11725번 트리의 부모 찾기
// 그래프 문제
// 주어진 트리에 대해 루트부터 그래프 탐색을 수행하면서 부모노드를 저장하여 해결 가능

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
