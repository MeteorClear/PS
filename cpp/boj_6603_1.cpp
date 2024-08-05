// https://www.acmicpc.net/problem/6603

#include <iostream>
#include <vector>

using namespace std;

void combination(int start, auto& S, auto& current, auto& result) {
    if (current.size() >= 6) {
        result.push_back(current);
        return;
    }
    for (int i=start; i<S.size(); i++) {
        current.push_back(S[i]);
        combination(i+1, S, current, result);
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        int N;
        cin >> N;
        
        if (N == 0) break;
        
        vector<int> S(N), current;
        vector<vector<int>> result;
        
        for (int i=0; i<N; i++) {
            cin >> S[i];
        }
        
        combination(0, S, current, result);
        
        for (auto i : result) {
            for (auto j : i) {
                cout << j << ' ';
            } cout << '\n';
        }
        
        cout << '\n';
    }
    return 0;
}
