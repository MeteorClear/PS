// https://www.acmicpc.net/problem/4803

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int t=1; ; ++t) {
        int n, m;
        cin >> n >> m;
        if (!n && !m) break;
        
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        int tree_count = 0;
        
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        
        for (int i=0; i<n; ++i) {
            if (visited[i]) continue;
            
            bool is_tree = true;
            vector<pair<int, int>> stack;
            stack.push_back({i, -1});
            
            while (!stack.empty()) {
                auto [current, parent] = stack.back();
                stack.pop_back();
                
                if (visited[current]) {
                    is_tree = false;
                    break;
                }
                visited[current] = true;
                
                for (auto neighbor : graph[current]) {
                    if (neighbor == parent) continue;
                    stack.push_back({neighbor, current});
                }
            }
            
            if (is_tree) ++tree_count;
        }
        
        string res = "No trees.";
        if (tree_count > 1) res = "A forest of "+to_string(tree_count)+" trees.";
        else if (tree_count == 1) res = "There is one tree.";
        
        cout << "Case " << t << ": " << res << '\n';
    }

    return 0;
}
