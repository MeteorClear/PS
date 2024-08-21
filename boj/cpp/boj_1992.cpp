// https://www.acmicpc.net/problem/1992

#include <iostream>
#include <vector>

using namespace std;

void compression(vector<vector<char>>& v, int y, int x, int n) {
    char p = v[y][x];
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
        cout << p;
        return;
    }
    
    cout << '(';
    
    int k = n/2;
    for (int i=0; i<2; ++i) {
        for (int j=0; j<2; ++j) {
            compression(v, y+i*k, x+j*k, k);
        }
    }
    
    cout << ')';
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<vector<char>> v(N, vector<char>(N));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> v[i][j];
        }
    }
    
    compression(v, 0, 0, N);

    return 0;
}
