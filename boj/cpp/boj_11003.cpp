// https://www.acmicpc.net/problem/11003
// 11003번 최솟값 찾기
// 덱, 우선순위 큐, 슬라이딩 윈도우 문제
// 길이 L 크기의 윈도우를 이용하여 최솟값을 추적하여 해결 가능
// 최소값 유지를 위해 우선순위 큐(최소 힙)를 활용
// 윈도우의 실제 값을 유지할 덱(dq)과 현재까지 들어온 값 중 최솟값 후보를 가지는 우선순위 큐(pq)와 범위 밖 수를 제어할 우선순위 큐(ban)
// 새로운 값이 들어오면 dq와 pq에 추가
// 만약 윈도우 크기 L을 초과시 dq의 front을 제거하여 ban에 저장
// pq와 ban의 top이 같으면 모두 제거하여 유효한 최솟값을 유지
// pq의 top은 윈도우 내 최솟값이 됨, (범위 밖 최솟값들은 위 과정으로 제거됨)

#include <iostream>
#include <deque>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L, A;
    cin >> N >> L;
    
    deque<int> dq;
    priority_queue<int, vector<int>, greater<int>> pq, ban;
    
    while (N--) {
        cin >> A;
        
        dq.push_back(A);
        pq.push(A);
        
        if (dq.size() > L) {
            ban.push(dq.front());
            dq.pop_front();
            while(!ban.empty() && ban.top() <= pq.top()) {
                ban.pop();
                pq.pop();
            }
        }
        
        cout << pq.top() << ' ';
    }

    return 0;
}
