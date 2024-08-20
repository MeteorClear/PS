// https://www.acmicpc.net/problem/2630

#include <iostream>
#include <vector>

using namespace std;

void count(vector<vector<int>>& v, vector<int>& res, int y, int x, int n) {
    int p = v[y][x];
    bool is_correct = true;
    for (int i=y; i<y+n; ++i) {
        for (int j=x; j<x+n; ++j) {
            if (v[i][j] != p) {
                is_correct = false;
                break;
            }
        }
        if (!is_correct) break;
    }
    
    if (is_correct) {
        ++res[p];
        return;
    }
    
    int k = n/2;
    for (int i=0; i<2; ++i) {
        for (int j=0; j<2; ++j) {
            count(v, res, y+i*k, x+j*k, k);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<vector<int>> v(N, vector<int>(N));
    vector<int> res(2, 0);
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> v[i][j];
        }
    }
    
    count(v, res, 0, 0, N);
    
    cout << res[0] << '\n' << res[1];

    return 0;
}
