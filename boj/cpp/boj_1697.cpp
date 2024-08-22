// https://www.acmicpc.net/problem/1697

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
    vector<bool> visited(100001, false);
    
    visited[N] = true;
    q.push({N, 0});
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        if (cur.first == K) {
            cout << cur.second;
            break;
        }
        
        int next[3] = {cur.first-1, cur.first+1, cur.first*2};
        for(int dir : next) {
            if (dir < 0 || dir >= 100001) continue;
            if (visited[dir]) continue;
            
            visited[dir] = true;
            q.push({dir, cur.second+1});
        }
    }

    return 0;
}
