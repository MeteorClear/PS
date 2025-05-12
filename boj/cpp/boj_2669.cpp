// https://www.acmicpc.net/problem/2669

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<bool>> field(101, vector<bool>(101, false));
    
    for (int k=0; k<4; ++k) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int i=x1; i<x2; ++i) {
            for (int j=y1; j<y2; ++j) {
                field[i][j] = true;
            }
        }
    }
    
    int cnt = 0;
    for (int i=0; i<=100; ++i) {
        for (int j=0; j<=100; ++j) {
            if (field[i][j]) ++cnt;
        }
    }
    
    cout << cnt;

    return 0;
}
