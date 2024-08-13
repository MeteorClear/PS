// https://www.acmicpc.net/problem/5427

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
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int w, h;
        cin >> w >> h;
        
        char building[h][w] = {};
        bool visited[h][w] = {};
        int sx, sy;
        queue<P> q;
        
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                cin >> building[i][j];
                if (building[i][j] == '@') {
                    sx = j; sy = i;
                } else if (building[i][j] == '*') {
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
            
            if (!cur.f && (cur.x == 0 || cur.x == w-1 || cur.y == 0 || cur.y == h-1)) {
                is_escape = true;
                res = cur.d;
                break;
            }
            
            for (int dir=0; dir<4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (visited[ny][nx] || building[ny][nx] == '#') continue;
                
                q.push({nx, ny, cur.d+1, cur.f});
            }
        }
        
        if (is_escape) {
            cout << res+1 << '\n';
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}
