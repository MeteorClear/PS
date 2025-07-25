// https://www.acmicpc.net/problem/12993
// 12993번 이동3
// 수학, 그래프 문제
// bfs를 응용하여 증가폭이 k^3이 되도록 탐색하여 해결 가능

#include <iostream>
#include <queue>

using namespace std;

struct P {
    int x;
    int y;
    int l;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x, y;
    cin >> x >> y;
    
    queue<P> q;
    q.push({0, 0, 1});
    
    bool is_found = false;
    
    while (!q.empty()) {
        auto [cx, cy, level] = q.front();
        q.pop();
        
        if (cx == x && cy == y) {
            is_found = true;
            break;
        }
        
        if (cx + level <= x) {
            q.push({cx + level, cy, level * 3});
        }
        
        if (cy + level <= y) {
            q.push({cx, cy + level, level * 3});
        }
    }
    
    cout << (int)is_found;
    
    return 0;
}
