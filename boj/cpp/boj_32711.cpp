// https://www.acmicpc.net/problem/32711

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector prefix_sum(N+1, 0);
    for (int i=1; i<=N; ++i) {
        int A;
        cin >> A;
        prefix_sum[i] = (prefix_sum[i-1] + A) % 2;
    }
    
    bool is_divided = false;
    if (prefix_sum[N] == 1) {
        is_divided = true;
    } else {
        for (int i=1; i<N; ++i) {
            if (prefix_sum[i] == 0) {
                is_divided = true;
                break;
            }
        }
    }
    
    cout << (int)is_divided;
    
    return 0;
}
