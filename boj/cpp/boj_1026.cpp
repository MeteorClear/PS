// https://www.acmicpc.net/problem/1026

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> A(N), B(N);
    
    for (int i=0; i<N; ++i) cin >> A[i];
    for (int i=0; i<N; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    int res = 0;
    for (int i=0; i<N; ++i) {
        res += A[i] * B[i];
    }
    
    cout << res;
    
    return 0;
}
