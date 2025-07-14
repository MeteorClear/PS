// https://www.acmicpc.net/problem/11729
// 11729번 하노이 탑 이동 순서
// 구현, 재귀 문제
// 3기둥 하노이 탑 알고리즘을 이용해 해결 가능
// hanoi(n, from, by, to)
// n-1개의 원판을 보조 기둥(by)로 이동
// 가장 큰 원판을 목적지(to)로 이동
// n-1개의 원판을 목적지로 이동

#include <iostream>

using namespace std;

void hanoi(int n, int from, int by, int to) {
    if (n == 0) return;
    
    hanoi(n-1, from, to, by);
    
    cout << from << ' ' << to << '\n';
    
    hanoi(n-1, by, from, to);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    cout << (1<<N)-1 << '\n';
    hanoi(N, 1, 2, 3);

    return 0;
}
