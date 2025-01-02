// https://www.acmicpc.net/problem/1991

#include <iostream>
#include <vector>

using namespace std;

void order(vector<pair<int, int>>& tree, int node, int mode) {
    if (node < 0 || node > 26) return;
    
    if (mode == 1) cout << (char)(node + 'A');
    order(tree, tree[node].first, mode);
    if (mode == 2) cout << (char)(node + 'A');
    order(tree, tree[node].second, mode);
    if (mode == 3) cout << (char)(node + 'A');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> tree(N, pair<int, int>({-1, -1}));
    
    for (int i=0; i<N; ++i) {
        char node, left, right;
        cin >> node >> left >> right;
        tree[node - 'A'] = {left - 'A', right - 'A'};
    }
    
    for (int i=1; i<=3; ++i) {
        order(tree, 0, i);
        cout << '\n';
    }
    
    return 0;
}
