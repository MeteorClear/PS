// https://www.acmicpc.net/problem/11286
// 11286번 절대값 힙
// 우선순위 큐 문제
// 절댓값 기준 오름차순, 절댓값이 같으면 실제 값 오름차순으로 정렬하여 해결 가능
// 절대값, 실제값을 모두 사용하고 음수값을 사용하여 최소힙을 구현

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<pair<int, int>> pq;
    
    int N;
    cin >> N;
    
    while (N--) {
        int x;
        cin >> x;
        
        if (x) {
            pq.push({-abs(x), -x});
            continue;
        }
        
        if (pq.empty()) {
            cout << "0\n";
            continue;
        }
        
        cout << -pq.top().second << '\n';
        pq.pop();
    }
    
    return 0;
}
