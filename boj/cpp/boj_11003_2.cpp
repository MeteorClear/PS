// https://www.acmicpc.net/problem/11003
// 11003번 최솟값 찾기
// 덱, 우선순위 큐, 슬라이딩 윈도우 문제
// 길이 L 크기의 윈도우를 이용하여 최솟값을 추적하여 해결 가능
// 덱을 활용하여 front에 최솟값이 오도록 유지
// 새로운 값 A가 들어오면 윈도우 범위 밖 인덱스에 대해서 제거
// 새로운 값 A보다 큰 값은 현 윈도우 범위에서 최솟값이 될 수 없으므로 back에서 제거
// 새로운 값 A를 덱 뒤에 삽입
// 덱의 front는 범위 L에서 최솟값을 가짐

#include <iostream>
#include <deque>

using namespace std;

struct E {
    int a;
    int idx;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L;
    cin >> N >> L;
    
    deque<E> dq;
    
    for (int i=0; i<N; i++) {
        int A;
        cin >> A;
        
        while (!dq.empty() && i-dq.front().idx >= L) dq.pop_front();
        while (!dq.empty() && dq.back().a >= A) dq.pop_back();
        
        dq.push_back({A, i});
        
        cout << dq.front().a << ' ';
    }

    return 0;
}
