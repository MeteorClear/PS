https://www.acmicpc.net/problem/2822

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int, int>> score;
    for (int i=1; i<=8; ++i) {
        int temp;
        cin >> temp;
        score.push_back({temp, i});
    }
    
    sort(score.begin(), score.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return a.first > b.first;
    });
    
    for (auto [x, i] : score) {
        cout << i << ' ' << x << '\n';
    }
    
    return 0;
}
