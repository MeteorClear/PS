// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct P {
    int y;
    int x;
    int d;
    bool b;
};

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> board(N, vector<int>(M));
    vector<vector<vector<bool>>> visited(
            N, vector<vector<bool>>(
            M, vector<bool>(2, false)));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            char temp;
            cin >> temp;
            board[i][j] = (int)(temp - '0');
        }
    }
    
    queue<P> q;
    int res = -1;
    
    q.push({0, 0, 1, false});
    visited[0][0][0] = true;
    
    while (!q.empty()) {
        auto [cy, cx, cd, cb] = q.front();
        q.pop();
        
        if (cy == N-1 && cx == M-1) {
            res = cd;
            break;
        }
        
        for (int dir=0; dir<4; ++dir) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            
            if (!cb && board[ny][nx] == 1 && !visited[ny][nx][1]) {
                q.push({ny, nx, cd+1, true});
                visited[ny][nx][1] = true;
            }
            
            if (board[ny][nx] == 0 && !visited[ny][nx][(int)cb]) {
                q.push({ny, nx, cd+1, cb});
                visited[ny][nx][(int)cb] = true;
            }
        }
    }
    
    cout << res;
    
    return 0;
}
