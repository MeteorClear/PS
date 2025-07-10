// https://www.acmicpc.net/problem/1004
// 1004번 어린 왕자
// 수학, 기하 문제
// 출발점과 도착점 중 오직 한 점만 포함되는 원의 개수를 세면 해결 가능
// 둘 다 포함되면 진입/이탈 필요 없음
// 둘 다 미포함이면 경로에 영향 없음
// 둘 중 하나만 포함되면 진입 or 이탈 필요하므로 카운트 +1

#include <iostream>

using namespace std;

bool IsInside(int x1, int y1, int x2, int y2, int r) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy <= r * r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int x1, y1, x2, y2, n, res = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        for (int i=0; i<n; ++i) {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            
            bool start_inside = IsInside(x1, y1, cx, cy, r);
            bool end_inside = IsInside(x2, y2, cx, cy, r);
            
            if (start_inside ^ end_inside) ++res;
        }
        cout << res << '\n';
    }

    return 0;
}
