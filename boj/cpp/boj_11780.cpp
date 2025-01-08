// https://www.acmicpc.net/problem/11780

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    const int inf = 10'000'000;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    vector<vector<int>> path(n, vector<int>(n, -1));
    
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (c < dist[a-1][b-1]) {
            dist[a-1][b-1] = c;
            path[a-1][b-1] = b-1;
        }
    }
    
    for (int i=0; i<n; ++i) dist[i][i] = 0;
    
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (dist[i][j] == inf) dist[i][j] = 0;
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (dist[i][j] == 0 || path[i][j] == -1) {
                cout << "0\n";
                continue;
            }
            
            vector<int> next;
            int now = i;
            while (now != j) {
                next.push_back(now);
                now = path[now][j];
            }
            next.push_back(j);
            
            cout << next.size() << ' ';
            for (auto e : next) cout << e + 1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}
