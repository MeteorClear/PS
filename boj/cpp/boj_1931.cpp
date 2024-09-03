// https://www.acmicpc.net/problem/1931

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
    for (int i=0; i<N; ++i) {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }
    
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    
    int res = 0, cur = 0;
    for (auto e : v) {
        if (e.first >= cur) {
            ++res;
            cur = e.second;
        }
    }
    
    cout << res;

    return 0;
}
