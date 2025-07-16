// https://www.acmicpc.net/problem/12007
// 12007번 Field Reduction (Bronze)
// 수학, 브루트포스 문제
// 주어진 좌표 중 가장 크거나 작은 좌표를 제거하고 나머지 좌표를 포함하는 가장 작은 사각형을 구하여 해결 가능

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calArea(vector<pair<int, int>> v, int start, int end) {
    int min_x=40001, max_x=0, min_y=40001, max_y=0;
    for (int i=start; i<end; ++i) {
        auto [x, y] = v[i];
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }
    return ((max_x - min_x) * (max_y - min_y));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> vxy;
    vector<pair<int, int>> vyx;
    
    for (int i=0; i<N; ++i) {
        int x, y;
        cin >> x >> y;
        vxy.push_back({x, y});
        vyx.push_back({y, x});
    }
    sort(vxy.begin(), vxy.end());
    sort(vyx.begin(), vyx.end());
    
    int res = 40001 * 40001;
    res = min(res, calArea(vxy, 0, N-1));
    res = min(res, calArea(vxy, 1, N));
    res = min(res, calArea(vyx, 0, N-1));
    res = min(res, calArea(vyx, 1, N));

    cout << res;
    
    return 0;
}
