// https://www.acmicpc.net/problem/2448

#include <iostream>
#include <vector>

using namespace std;

void makeBoard(vector<vector<bool>>& v, int y, int x, int n) {
    if (n <= 3) {
        v[y][x] = true;
        v[y+1][x-1] = v[y+1][x+1] = true;
        for (int t=-2; t<3; ++t) v[y+2][x+t] = true;
        return;
    }
    
    int k = n/2;
    
    makeBoard(v, y, x, k);
    makeBoard(v, y+k, x-k, k);
    makeBoard(v, y+k, x+k, k);
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
    
    vector<vector<bool>> v(N, vector<bool>(2*N-1, false));
    
    makeBoard(v, 0, N-1, N);
    printBoard(v);

    return 0;
}
