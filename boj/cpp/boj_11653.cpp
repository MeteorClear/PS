// https://www.acmicpc.net/problem/11653
// 11653번 소인수분해
// 수학 문제
// 주어진 수를 소인수분해하여 오름차순으로 출력하여 해결 가능
// 2부터 sqrt(N) 까지 나눠지는지 검사하여 소인수분해를 할 수 있다

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    while (N > 1) {
        for (int i=2; i<=N; ++i) {
            if (N % i == 0) {
                cout << i << '\n';
                N /= i;
                break;
            }
        }
    }
    
    return 0;
}
