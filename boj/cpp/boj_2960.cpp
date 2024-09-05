// https://www.acmicpc.net/problem/2960

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K, p = 0, res = -1;
    cin >> N >> K;
    
    vector<bool> P(N+1);
    
    for (int i=2; i<=N; ++i) {
        if (!P[i]) {
            ++p;
            if (p == K) {
                res = i;
                break;
            }
            for (int j=2*i; j<=N; j+=i) {
                if (P[j]) continue;
                P[j] = true;
                ++p;
                if (p == K) {
                    res = j;
                    break;
                }
            }
        }
    }
    
    cout << res;

    return 0;
}
