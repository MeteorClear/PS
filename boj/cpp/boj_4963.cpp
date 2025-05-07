// https://www.acmicpc.net/problem/4963

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& map, int h, int w, int py, int px) {
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    map[py][px] = -1;
    
    for (int i=0; i<8; ++i) {
        int ny = py + dy[i];
        int nx = px + dx[i];
        
        if (ny < 0 || ny >= h) continue;
        if (nx < 0 || nx >= w) continue;
        if (map[ny][nx] != 1) continue;
        
        dfs(map, h, w, ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        int w, h;
        cin >> w >> h;
        
        if (!w && !h) break;
        
        vector<vector<int>> map(h, vector<int>(w, 0));
        
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                cin >> map[i][j];
            }
        }
        
        int cnt = 0;
        
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                if (map[i][j] != 1) continue;
                dfs(map, h, w, i, j);
                ++cnt;
            }
        }
        
        cout << cnt << '\n';
    }

    return 0;
}
