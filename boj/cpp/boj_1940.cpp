// https://www.acmicpc.net/problem/1940

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N, 0);
    for (auto& e : A) {
        cin >> e;
    }
    sort(A.begin(), A.end());
    
    int cnt = 0, left = 0, right = N-1;
    
    while (left < right) {
        int sum = A[left] + A[right];
        
        if (sum == M) {
            ++cnt;
            ++left;
            --right;
        } else if (sum < M) {
            ++left;
        } else {
            --right;
        }
    }
    
    cout << cnt;
    
    return 0;
}
