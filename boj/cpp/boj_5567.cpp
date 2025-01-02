// https://www.acmicpc.net/problem/5567

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> friends(n+1, vector<int>());
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    
    unordered_set<int> s;
    for (auto f : friends[1]) {
        s.insert(f);
        for (auto ff : friends[f]) {
            s.insert(ff);
        }
    }
    s.erase(1);
    
    cout << s.size();

    return 0;
}
