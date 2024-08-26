// https://www.acmicpc.net/problem/2447

#include <iostream>
#include <vector>

using namespace std;

void makeBoard(vector<vector<bool>>& v, int y, int x, int n) {
    if (n <= 1) {
        v[y][x] = true;
        return;
    }
    
    int k = n/3;
    
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            if (i==1 && j==1) continue;
            makeBoard(v, y+i*k, x+j*k, k);
        }
    }
}

void printBoard(vector<vector<bool>>& v) {
    for (auto i : v) {
        for (auto j : i) {
            cout << (j ? '*' : ' ');
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<vector<bool>> v(N, vector<bool>(N, false));
    
    makeBoard(v, 0, 0, N);
    printBoard(v);

    return 0;
}
