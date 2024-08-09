// https://www.acmicpc.net/problem/6593

#include <iostream>
#include <queue>

using namespace std;

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

struct P {
    int x;
    int y;
    int z;
    int d;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int L, R, C;
        cin >> L >> R >> C;
        
        if (!L && !R && !C) break;
        
        char building[L][R][C] = {};
        bool visited[L][R][C] = {};
        int cx, cy, cz, tx, ty, tz;
        queue<P> q;
        
        
        for (int i=0; i<L; i++) {
            for (int j=0; j<R; j++) {
                for (int k=0; k<C; k++) {
                    cin >> building[i][j][k];
                    if (building[i][j][k] == 'S') {
                        cz = i; cy = j; cx = k;
                    } else if (building[i][j][k] == 'E') {
                        tz = i; ty = j; tx = k;
                    }
                }
            }
        }
        
        bool is_escape = false;
        int time_spent = -1;
        
        q.push({cx, cy, cz, 0});
        visited[cz][cy][cx] = true;
        
        while (!q.empty()) {
            P cur = q.front();
            q.pop();
            
            if (cur.x == tx && cur.y == ty && cur.z == tz) {
                is_escape = true;
                time_spent = cur.d;
            }
            
            for (int dir=0; dir<6; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                int nz = cur.z + dz[dir];
                
                if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                if (visited[nz][ny][nx] || building[nz][ny][nx] == '#') continue;
                
                visited[nz][ny][nx] = true;
                q.push({nx, ny, nz, cur.d+1});
            }
        }
        
        if (is_escape) cout << "Escaped in " << time_spent << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}
