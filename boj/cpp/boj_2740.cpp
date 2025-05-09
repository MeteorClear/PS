// https://www.acmicpc.net/problem/2740

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, K;
    
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> A[i][j];
        }
    }
    
    cin >> M >> K;
    vector<vector<int>> B(M, vector<int>(K));
    for (int i=0; i<M; ++i) {
        for (int j=0; j<K; ++j) {
            cin >> B[i][j];
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<K; ++j) {
            int element = 0;
            for (int k=0; k<M; ++k) {
                element += A[i][k] * B[k][j];
            }
            cout << element << ' ';
        }
        cout << '\n';
    }

    return 0;
}
