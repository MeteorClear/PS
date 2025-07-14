// https://www.acmicpc.net/problem/11650
// 11650번 좌표 정렬하기
// 정렬 문제
// 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬하여 해결 가능

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
        v.push_back({x, y});
    }
    
    sort(v.begin(), v.end());
    
    for (auto [x, y] : v) {
        cout << x << ' ' << y << '\n';
    }

    return 0;
}
