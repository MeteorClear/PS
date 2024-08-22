// https://www.acmicpc.net/problem/13913

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    queue<pair<int, int>> q;
    vector<int> visited(100001, -1);
    
    visited[N] = -2;
    q.push({N, 0});
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        if (cur.first == K) {
            cout << cur.second << '\n';
            break;
        }
        
        int next[3] = {cur.first-1, cur.first+1, cur.first*2};
        for(int dir : next) {
            if (dir < 0 || dir >= 100001) continue;
            if (visited[dir] != -1) continue;
            
            visited[dir] = cur.first;
            q.push({dir, cur.second+1});
        }
    }
    
    vector<int> res;
    res.push_back(K);
    
    int k = visited[K];
    while (k != -2) {
        res.push_back(k);
        k = visited[k];
    }
    
    for (int i=res.size()-1; i>=0; --i) {
        cout << res[i] << ' ';
    }

    return 0;
}
