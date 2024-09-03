// https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i=0; i<N; ++i) {
        cin >> A[i];
    }
    
    int res = 0;
    for (int i=N-1; i>=0; --i) {
        res += K / A[i];
        K = K % A[i];
    }
    
    cout << res;

    return 0;
}
