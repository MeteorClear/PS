// https://www.acmicpc.net/problem/11003
// 11003번 최솟값 찾기
// 덱, 우선순위 큐, 슬라이딩 윈도우 문제
// 길이 L 크기의 윈도우를 이용하여 최솟값을 추적하여 해결 가능
// 음수값을 이용하여 최소힙 처럼 사용
// 각 값에 인덱스를 추가로 저장하여 범위 밖 인덱스의 경우 우선순위 큐에서 제거
// 우선순위 큐의 top은 해당 인덱스 범위에서 최솟값을 가짐

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L, A;
    cin >> N >> L;
    
    priority_queue<pair<int, int>> pq;
    
    for(int i=1; i<=N; i++) {
        cin >> A;
        pq.push({-A, i});
        
        while(!pq.empty() && i-pq.top().second >= L) {
            pq.pop();
        }
        
        cout << -(pq.top().first) << ' ';
    }

    return 0;
}
