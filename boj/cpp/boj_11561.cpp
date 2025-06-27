// https://www.acmicpc.net/problem/11561

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        long long N;
        cin >> N;
        
        long long k = (long long)((sqrtl(8.0L * N + 1) - 1) / 2);
        
        while ((k+1)*(k+2)/2 <= N) ++k;
        while (k*(k+1)/2 > N) --k;
        
        cout << k << '\n';
    }
    
    return 0;
}
