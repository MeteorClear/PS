// https://www.acmicpc.net/problem/1138

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, height;
    cin >> N;
    
    vector<int> res(N);
    
    for (int i=0; i<N; ++i) {
        cin >> height;
        int p = 0, j = 0;
        
        while (res[p] != 0) ++p;
        while (j < height) {
            ++p;
            if (res[p] != 0) continue;
            ++j;
        }
        
        res[p] = i + 1;
    }
    
    for (int i=0; i<N; ++i) cout << res[i] << ' ';

    return 0;
}
