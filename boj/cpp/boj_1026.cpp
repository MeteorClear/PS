// https://www.acmicpc.net/problem/1026
// 1026번 보물
// 정렬 문제
// 수열 A, B에 대해 각각 오름차순, 내림차순으로 정렬하여 계산하면 해결 가능
// 함수 S의 값이 최소가 되려면 B의 가장 큰 원소와 A의 가장 작은 원소가 곱해져야 함

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
