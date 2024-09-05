// https://www.acmicpc.net/problem/1193

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int X, s=0, i=1;
    cin >> X;
    
    while (X > s+i) {
        s += i;
        ++i;
    }
    
    int k = X - s;
    
    if (i & 1) cout << i-k+1 << '/' << k;
    else cout << k << '/' << i-k+1;

    return 0;
}
