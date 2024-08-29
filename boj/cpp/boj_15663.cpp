// https://www.acmicpc.net/problem/15663

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void combination(set<vector<int>>& visited, vector<int>& A, vector<int>& C, int M) {
    if (C.size() == M) {
        vector<int> temp(M);
        for (int t=0; t<M; ++t) {
            temp[t] = A[C[t]];
        }
        
        visited.insert(temp);
        return;
    }
    
    for (int i=0; i<A.size(); ++i) {
        if (find(C.begin(), C.end(), i) != C.end()) continue;
        
        C.push_back(i);
        combination(visited, A, C, M);
        C.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N), C;
    set<vector<int>> visited;
    
    for (int i=0; i<N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    combination(visited, A, C, M);
    
    for (auto& v : visited) {
        for (auto& e : v) {
            cout << e << ' ';
        }
        cout << '\n';
    }

    return 0;
}
