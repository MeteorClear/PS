// https://www.acmicpc.net/problem/14566

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (auto& e : A) {
        cin >> e;
    }
    sort(A.begin(), A.end());
    
    int base = 32800001, cnt = 0;
    for (int i=1; i<N; ++i) {
        int now = A[i] - A[i-1];
        if (now == base) {
            ++cnt;
        } else if (now < base) {
            base = now;
            cnt = 1;
        }
    }
    
    cout << base << ' ' << cnt;
    
    return 0;
}
