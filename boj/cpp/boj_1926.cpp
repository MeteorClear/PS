// https://www.acmicpc.net/problem/1926

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[501][501];
bool visit[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    
    int img=0, max_size=0;
    queue<pair<int, int>> q;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!visit[i][j] && map[i][j] == 1) {
                int temp_size = 0;
                img++;
                q.push({i, j});
                visit[i][j] = true;
                
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    temp_size++;
                    
                    for (int k=0; k<4; k++) {
                        int ny = cur.first + dy[k];
                        int nx = cur.second + dx[k];
                        
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        if (visit[ny][nx] || map[ny][nx] != 1) continue;
                        
                        visit[ny][nx] = true;
                        q.push({ny, nx});
                    }
                    max_size = max(max_size, temp_size);
                }
            }
        }
    }
    
    cout << img << '\n' << max_size;

    return 0;
}
