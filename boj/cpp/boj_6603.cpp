// https://www.acmicpc.net/problem/6603

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        int N;
        cin >> N;
        
        if (N == 0) break;
        
        vector<int> combination(N), select(N, 0);
        fill(select.begin(), select.begin()+6, 1);
        
        for (int i=0; i<N; i++) {
            cin >> combination[i];
        }
        
        do {
            for (int i=0; i<N; i++) {
                if (select[i]) {
                    cout << combination[i] << ' ';
                }
            }
            cout << '\n';
        } while (prev_permutation(select.begin(), select.end()));
        
        cout << '\n';
    }
    return 0;
}
