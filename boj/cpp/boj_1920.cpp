// https://www.acmicpc.net/problem/1920

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
    for (int i=0; i<N; ++i) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    int M;
    cin >> M;
    
    while (M--) {
        int target;
        cin >> target;
        
        bool res = binary_search(A.begin(), A.end(), target);
        cout << res << '\n';
    }

    return 0;
}
