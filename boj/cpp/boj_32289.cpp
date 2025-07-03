// https://www.acmicpc.net/problem/32289

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    cout << 4*n*m - 3*n - 3*m + 2;
    
    return 0;
}
