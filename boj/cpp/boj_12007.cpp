https://www.acmicpc.net/problem/12007

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
