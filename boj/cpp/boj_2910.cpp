// https://www.acmicpc.net/problem/2910

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, C;
    cin >> N >> C;
    
    vector<pair<int, int>> v;
    
    while (N--) {
        int temp;
        cin >> temp;
        
        bool chk = false;
        for (auto& [cnt, idx] : v) {
            if (idx == temp) {
                ++cnt;
                chk = true;
                break;
            }
        }
        if (chk) continue;
        
        v.push_back({1, temp});
    }
    
    stable_sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });
    
    for (auto& [cnt, idx] : v) {
        for (int i=0; i<cnt; ++i) {
            cout << idx << ' ';
        }
    }

    return 0;
}
