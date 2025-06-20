// https://www.acmicpc.net/problem/9625

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int K;
    cin >> K;
    
    int A = 0, B = 1;
    
    for (int i=2; i<=K; ++i) {
        int temp = B;
        B = A + B;
        A = temp;
    }
    
    cout << A << ' ' << B;

    return 0;
}
