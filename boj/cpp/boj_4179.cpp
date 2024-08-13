// https://www.acmicpc.net/problem/4179

#include <iostream>
#include <queue>

using namespace std;

struct P {
    int x;
    int y;
    int d;
    bool f;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int R, C;
    cin >> R >> C;
    
    char building[R][C] = {};
    bool visited[R][C] = {};
    int sx, sy;
    queue<P> q;
    
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            cin >> building[i][j];
            if (building[i][j] == 'J') {
                sx = j; sy = i;
            } else if (building[i][j] == 'F') {
                q.push({j, i, 0, true});
            }
        }
    }
    q.push({sx, sy, 0, false});
    
    bool is_escape = false;
    int res = -1;
    
    while(!q.empty()) {
        P cur = q.front();
        q.pop();
        
        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;
        
        if (!cur.f && (cur.x == 0 || cur.x == C-1 || cur.y == 0 || cur.y == R-1)) {
            is_escape = true;
            res = cur.d;
            break;
        }
        
        for (int dir=0; dir<4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
            if (visited[ny][nx] || building[ny][nx] == '#') continue;
            
            q.push({nx, ny, cur.d+1, cur.f});
        }
    }
    
    if (is_escape) {
        cout << res+1 << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
