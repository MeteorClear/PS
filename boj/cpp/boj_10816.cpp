// https://www.acmicpc.net/problem/10816

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

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
        
        auto [it1, it2] = equal_range(A.begin(), A.end(), target);
        cout << distance(it1, it2) << ' ';
    }

    return 0;
}
