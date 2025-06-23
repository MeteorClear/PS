// https://www.acmicpc.net/problem/1748

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, base = 9, offset = 1, total = 0;
    cin >> N;
    
    while (N > base) {
        N -= base;
        total += base * offset;
        base *= 10;
        ++offset;
        
    }
    total += N * offset;
    
    cout << total;
    
    return 0;
}
