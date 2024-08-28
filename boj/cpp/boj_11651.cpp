// https://www.acmicpc.net/problem/11651

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
