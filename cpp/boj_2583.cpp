// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    
    int board[N][M] = {};
    
    while(K--) {
        int lx, ly, rx, ry;
        cin >> ly >> lx >> ry >> rx;
        
        for (int i=ly; i<ry; ++i) {
            for (int j=lx; j<rx; ++j) {
                board[i][j] = -1;
            }
        }
    }
    
    vector<int> res;
    vector<pair<int, int>> s;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (board[i][j] == 0) {
                int count = 1;
                board[i][j] = 1;
                s.push_back({i, j});
                
                while(!s.empty()) {
                    pair<int, int> cur = s.back();
                    s.pop_back();
                    
                    for (int dir=0; dir<4; dir++) {
                        int nx = cur.second + dx[dir];
                        int ny = cur.first + dy[dir];
                        
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if (board[ny][nx] != 0) continue;
                        
                        count++;
                        board[ny][nx] = 1;
                        s.push_back({ny, nx});
                    }
                }
                res.push_back(count);
            }
        }
    }
    sort(res.begin(), res.end());
    
    cout << res.size() << '\n';
    for (auto p : res) cout << p << ' ';

    return 0;
}
