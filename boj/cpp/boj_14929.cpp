// https://www.acmicpc.net/problem/14929

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    long long prefix_sum = 0, square_sum = 0;
    for (int i=0; i<n; ++i) {
        long long x;
        cin >> x;
        prefix_sum += x;
        square_sum += x * x;
    }
    
    cout << (prefix_sum * prefix_sum - square_sum) / 2;
    
    return 0;
}
