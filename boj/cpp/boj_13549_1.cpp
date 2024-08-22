// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    deque<pair<int, int>> dq;
    vector<int> visited(100001, -1);
    
    dq.push_front({0, N});
    visited[N] = 0;
    
    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop_front();
        
        if (cur.second == K) {
            cout << cur.first;
            break;
        }
        
        int next[3] = {cur.second*2, cur.second+1, cur.second-1};
        int weight[3] = {0, 1, 1};
        
        for (int dir=0; dir<3; ++dir) {
            if (next[dir] < 0 || next[dir] >= 100001) continue;
            if (visited[next[dir]] == -1 || visited[next[dir]] > cur.first + weight[dir]) {
                visited[next[dir]] = cur.first + weight[dir];
                if (weight[dir]) {
                    dq.push_back({cur.first + weight[dir], next[dir]});
                } else {
                    dq.push_front({cur.first + weight[dir], next[dir]});
                }
            }
        }
    }

    return 0;
}
