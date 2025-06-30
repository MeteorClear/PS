// https://www.acmicpc.net/problem/12993

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x, y;
    cin >> x >> y;
    
    if (x == 0 && y == 0) {
        cout << 1;
        return 0;
    }
    
    while (x || y) {
        int dx = x % 3;
        int dy = y % 3;
        if (dx == dy || dx > 1 || dy > 1) {
            cout << 0;
            return 0;
        }
        x /= 3;
        y /= 3;
    }
    
    cout << 1;
    
    return 0;
}
