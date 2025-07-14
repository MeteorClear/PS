// https://www.acmicpc.net/problem/11561
// 11561번 징검다리
// 수학, 누적합 문제
// 1~k 까지의 "누적합 N"보다 작은 "가장 큰 k"를 구하여 해결 가능
// 점프 거리의 누적합은 1 + 2 + 3 + ... + k = k*(k+1)/2
// k*(k+1)/2 ≤ N 의 식을 변형하여 2N ≤ k² + k
// 근사해 풀기 위해 근의 공식 유도: k ≈ (sqrt(8N + 1) - 1) / 2
// 근사해를 구한 후 미세 조정하여 최적해를 구함

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        long long N;
        cin >> N;
        
        long long k = (long long)((sqrtl(8.0L * N + 1) - 1) / 2);
        
        while ((k+1)*(k+2)/2 <= N) ++k;
        while (k*(k+1)/2 > N) --k;
        
        cout << k << '\n';
    }
    
    return 0;
}
