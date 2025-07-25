// https://www.acmicpc.net/problem/12993
// 12993번 이동3
// 수학, 그리디 문제
// 각 한자리씩 3진법으로 검사하여 해결 가능
// x, y 각 자리수 비교, (0,1) 또는 (1,0)일 경우에만 이동 가능
// 같은 자리에서 x와 y가 모두 0이거나 모두 1이거나 2 이상이면 불가능

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
