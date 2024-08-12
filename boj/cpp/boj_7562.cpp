// https://www.acmicpc.net/problem/7562

#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

struct P {
    int x;
    int y;
    int d;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        bool visited[301][301]={};
        int l, cx, cy, tx, ty, count=0;
        cin >> l >> cx >> cy >> tx >> ty;
        
        queue<P> q;
        q.push({cx, cy, 0});
        visited[cx][cy] = true;
        
        while (!q.empty()) {
            P cur = q.front();
            q.pop();
            if (cur.x == tx && cur.y == ty) {
                count = cur.d;
                break;
            }
            
            for (int i=0; i<8; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (visited[nx][ny]) continue;
                
                visited[nx][ny] = true;
                q.push({nx, ny, cur.d+1});
            }
        }
        cout << count << '\n';
    }
    return 0;
}
