// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int area[N][N] = {};
    int max_level = 0, res = -1;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> area[i][j];
            max_level = max(max_level, area[i][j]);
        }
    }
    
    for (int level=0; level<=max_level; ++level) {
        int safe = 0;
        bool visited[N][N] = {};
        vector<pair<int, int>> s;
        
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (area[i][j] > level && !visited[i][j]) {
                    ++safe;
                    visited[i][j] = true;
                    s.push_back({i, j});
                    
                    while (!s.empty()) {
                        pair<int, int> cur = s.back();
                        s.pop_back();
                        
                        for (int dir=0; dir<4; ++dir) {
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            
                            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                            if (area[ny][nx] <= level || visited[ny][nx]) continue;
                            
                            visited[ny][nx] = true;
                            s.push_back({ny, nx});
                        }
                    }
                }
            }
        }
        res = max(res, safe);
    }
    
    cout << res;
    
    return 0;
}
