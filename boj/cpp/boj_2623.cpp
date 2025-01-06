// https://www.acmicpc.net/problem/2623

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> order(N, vector<int>({}));
    vector<int> indegree(N);
    
    while (M--) {
        int PD;
        cin >> PD;
        
        vector<int> data;
        while (PD--) {
            int temp;
            cin >> temp;
            data.push_back(temp);
        }
        
        for (int i=0; i<data.size()-1; ++i) {
            int A = data[i];
            int B = data[i+1];
            
            order[A-1].push_back(B-1);
            ++indegree[B-1];
        }
    }
    
    queue<int> q;
    for (int i=0; i<N; ++i) {
        if (!indegree[i]) q.push(i);
    }
    
    vector<int> res;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        res.push_back(cur + 1);
        for (auto neighbor : order[cur]) {
            --indegree[neighbor];
            if (!indegree[neighbor]) q.push(neighbor);
        }
    }
    
    if (res.size() != N) {
        cout << 0;
    } else {
        for (auto e : res) {
            cout << e << '\n';
        }
    }

    return 0;
}
