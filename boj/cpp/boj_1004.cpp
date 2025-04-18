// https://www.acmicpc.net/problem/1004

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
