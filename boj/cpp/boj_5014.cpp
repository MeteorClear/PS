// https://www.acmicpc.net/problem/5014

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    
    bool building[F+1] = {};
    int d[2] = {U, -D};
    queue<pair<int, int>> q;
    
    q.push({S, 0});
    building[S] = true;
    bool is_find = false;
    int res;
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        if (cur.first == G) {
            is_find = true;
            res = cur.second;
            break;
        }
        
        for (int dir=0; dir<2; ++dir) {
            int next = cur.first + d[dir];
            
            if (next <= 0 || next > F) continue;
            if (building[next]) continue;
            
            building[next] = true;
            q.push({next, cur.second+1});
        }
    }
    
    if (is_find) cout << res;
    else cout << "use the stairs";

    return 0;
}
