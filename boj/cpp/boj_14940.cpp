// https://www.acmicpc.net/problem/14940

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int y;
    int x;
    int d;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, pos_y, pos_x;
    cin >> n >> m;
    
    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> map[i][j];
            
            if (map[i][j] == 2) {
                pos_y = i;
                pos_x = j;
            }
        }
    }
    
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    vector<vector<int>> distance(n, vector<int>(m, -1));
    queue<Pos> q;
    q.push({pos_y, pos_x, 1});
    distance[pos_y][pos_x] = 0;
    
    while (!q.empty()) {
        auto [cy, cx, cd] = q.front();
        q.pop();
        
        for (int i=0; i<4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (map[ny][nx] == 0) continue;
            if (distance[ny][nx] != -1) continue;
            
            q.push({ny, nx, cd+1});
            distance[ny][nx] = cd;
        }
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (map[i][j] == 0) cout << 0 << ' ';
            else cout << distance[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
