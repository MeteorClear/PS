// https://www.acmicpc.net/problem/15652

#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int>& p, int k, int n, int m) {
    if (p.size() == m) {
        for (auto e : p) {
            cout << e << ' ';
        } cout << '\n';
        return;
    }
    
    for (int i=k; i<=n; ++i) {
        p.push_back(i);
        permutation(p, i, n, m);
        p.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> p;
    
    permutation(p, 1, N, M);
    
    return 0;
}
