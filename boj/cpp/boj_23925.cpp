// https://www.acmicpc.net/problem/23925

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int i=1; i<=T; ++i) {
        long long N, K, S;
        cin >> N >> K >> S;
        cout << "Case #" << i << ": " << min(N+K, K+(K-S)+(N-S)) << '\n';
    }

    return 0;
}
