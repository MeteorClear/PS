// https://www.acmicpc.net/problem/10816
// 10816번 숫자 카드 2
// 정렬, 범위 탐색 문제
// 상근이는 숫자 카드를 정렬한 후 수가 들어올 때마다 탐색 후 숫자 범위 크기로 해결 가능

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
