// https://www.acmicpc.net/problem/11653

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
