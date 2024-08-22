// https://www.acmicpc.net/problem/2573

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> sea(N, vector<int>(M));
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int maxlevel = 0;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> sea[i][j];
        }
    }
    
    for(int year=0; ; ++year) {
        int count = 0;
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<pair<int, int>> q, change;
        
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (sea[i][j] > 0 && !visited[i][j]) {
                    visited[i][j] = true;
                    q.push({i, j});
                    ++count;
                    
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        
                        for (int dir=0; dir<4; ++dir) {
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            
                            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                            if (sea[ny][nx] == 0) {
                                change.push({cur.first, cur.second});
                                continue;
                            }
                            if (visited[ny][nx]) continue;
                            
                            visited[ny][nx] = true;
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }
        
        if (count != 1) {
            cout << (count == 0 ? 0 : year);
            break;
        }
        
        while (!change.empty()) {
            pair<int, int> cur = change.front();
            change.pop();
            sea[cur.first][cur.second] = max(0, sea[cur.first][cur.second]-1);
        }
    }

    return 0;
}
