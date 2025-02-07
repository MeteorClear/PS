// https://www.acmicpc.net/problem/24416

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int fibo[41];
    fibo[1] = fibo[2] = 1;
    for (int i=3; i<=n; ++i) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    cout << fibo[n] << ' ' << n-2;

    return 0;
}
