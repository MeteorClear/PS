// https://www.acmicpc.net/problem/21736

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, pos_y, pos_x;
    cin >> N >> M;
    
    vector<vector<char>> campus(N, vector<char>(M));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> campus[i][j];
            
            if (campus[i][j] == 'I') {
                pos_y = i;
                pos_x = j;
            }
        }
    }
    
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    int cnt = 0;
    
    queue<pair<int, int>> q;
    q.push({pos_y, pos_x});
    campus[pos_y][pos_x] = 'X';
    
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        
        for (int i=0; i<4; ++i) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (campus[ny][nx] == 'X') continue;
            if (campus[ny][nx] == 'P') ++cnt;
            
            q.push({ny, nx});
            campus[ny][nx] = 'X';
        }
    }
    
    if (cnt) cout << cnt;
    else cout << "TT";

    return 0;
}
