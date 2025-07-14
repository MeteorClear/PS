// https://www.acmicpc.net/problem/11651
// 11651번 좌표 정렬하기 2
// 정렬 문제
// 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬하여 해결 가능

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> v;
    while (N--) {
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }
    
    sort(v.begin(), v.end());
    
    for (auto [y, x] : v) {
        cout << x << ' ' << y << '\n';
    }

    return 0;
}
