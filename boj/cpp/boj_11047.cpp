// https://www.acmicpc.net/problem/11047
// 11047번 동전 0
// 그리디 문제
// 가장 큰 동전 크기 순서대로 세어서 해결 가능
// i ≥ 2인 경우에 A_i는 A_{i-1}의 배수라는 조건이 있으므로
// 가장 큰 동선 순으로 나머지와 몫을 이용해 계산하면 동전 개수의 최솟값이 된다

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
