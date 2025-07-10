// https://www.acmicpc.net/problem/10815
// 10815번 숫자 카드
// 이분 탐색 문제
// 상근이가 가지고 있는 숫자 카드를 정렬한 후, 숫자가 주어질 때마다 이분 탐색하여 해결 가능

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
        cout << res << ' ';
    }

    return 0;
}
