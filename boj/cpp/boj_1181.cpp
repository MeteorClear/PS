// https://www.acmicpc.net/problem/1181

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<string> v;
    set<string> s;
    
    for (int i=0; i<N; ++i) {
        string temp;
        cin >> temp;
        s.insert(temp);
    }
    
    for (auto e : s) {
        v.push_back(e);
    }
    
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size();
    });
    
    for (auto& e : v) {
        cout << e << '\n';
    }

    return 0;
}
