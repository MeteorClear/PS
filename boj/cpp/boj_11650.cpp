// https://www.acmicpc.net/problem/11650

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
