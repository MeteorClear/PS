// https://www.acmicpc.net/problem/1074

#include <iostream>
#include <cmath>

using namespace std;

int find(int r, int c, int n) {
    if (n <= 2) return r*2+c;
    
    int y = (int)(r >= n/2);
    int x = (int)(c >= n/2);
    
    if (y) r -= n/2;
    if (x) c -= n/2;
    
    int now = pow(n/2, 2);
    int nowPos = now*y*2 + now*x;
    
    return nowPos + find(r, c, n/2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, r, c;
    cin >> N >> r >> c;
    
    int res = find(r, c, pow(2, N));
    cout << res;

    return 0;
}
