// https://www.acmicpc.net/problem/17087

#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, S, A;
    cin >> N >> S;

    cin >> A;
    --N;
    
    int res = abs(S-A);
    
    while (N--) {
        cin >> A;
        res = gcd(res, abs(S-A));
        if (res == 1) break;
    }
    
    cout << res;

    return 0;
}
