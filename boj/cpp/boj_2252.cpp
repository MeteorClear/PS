// https://www.acmicpc.net/problem/2252

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> student_list(N, vector<int>({}));
    vector<int> indegree(N);
    
    while (M--) {
        int A, B;
        cin >> A >> B;
        
        student_list[A-1].push_back(B-1);
        ++indegree[B-1];
    }
    
    queue<int> q;
    for (int i=0; i<N; ++i) {
        if (!indegree[i]) q.push(i);
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        cout << cur + 1 << ' ';
        for (auto neighbor : student_list[cur]) {
            --indegree[neighbor];
            if (!indegree[neighbor]) q.push(neighbor);
        }
    }

    return 0;
}
