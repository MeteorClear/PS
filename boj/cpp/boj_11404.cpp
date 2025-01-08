// https://www.acmicpc.net/problem/11404

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    const int inf = 10'000'000;
    vector<vector<int>> path(n, vector<int>(n, inf));
    
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        path[a-1][b-1] = min(path[a-1][b-1], c);
    }
    
    for (int i=0; i<n; ++i) path[i][i] = 0;
    
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (path[i][j] == inf) path[i][j] = 0;
            cout << path[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
