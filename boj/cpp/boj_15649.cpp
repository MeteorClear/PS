// https://www.acmicpc.net/problem/15649

#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int>& p, int n, int m) {
    if (p.size() == m) {
        for (auto e : p) {
            cout << e << ' ';
        } cout << '\n';
        return;
    }
    
    for (int i=1; i<=n; ++i) {
        bool chk = false;
        for (auto e : p) {
            if (e == i) {
                chk = true;
                break;
            }
        }
        if (chk) continue;
        
        p.push_back(i);
        permutation(p, n, m);
        p.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> p;
    
    permutation(p, N, M);
    
    return 0;
}
