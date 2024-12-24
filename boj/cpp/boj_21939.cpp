// https://www.acmicpc.net/problem/21939

#include <iostream>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<int, set<int>> level_problem;
    unordered_map<int, int> problem_level;
    
    int N;
    cin >> N;
    while (N--) {
        int P, L;
        cin >> P >> L;
        
        level_problem[L].insert(P);
        problem_level[P] = L;
    }
    
    int M;
    cin >> M;
    while (M--) {
        string command;
        cin >> command;
        
        if (command == "recommend") {
            int x;
            cin >> x;
            
            if (x == 1) {
                auto highest_level = level_problem.rbegin()->first;
                auto max_val = *level_problem[highest_level].rbegin();
                cout << max_val << '\n';
            } else {
                auto lowest_level = level_problem.begin()->first;
                auto min_val = *level_problem[lowest_level].begin();
                cout << min_val << '\n';
            }
            
        } else if (command == "solved") {
            int P;
            cin >> P;
            
            int target = problem_level[P];
            problem_level.erase(P);
            
            level_problem[target].erase(P);
            if (level_problem[target].empty()) {
                level_problem.erase(target);
            }
            
        } else {
            int P, L;
            cin >> P >> L;
            
            level_problem[L].insert(P);
            problem_level[P] = L;
        }
    }

    return 0;
}
