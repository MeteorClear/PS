// https://www.acmicpc.net/problem/1193
// 1193번 분수찾기
// 수학 문제
// X번째 분수가 몇 번째 줄인지 찾고 해당 줄에서 몇 번째 항인지 구하여 해결 가능
// 누적합을 이용해 몇번째 줄(i)인지 찾음, 해당 줄(i)에서 몇 번째 항인지
// i가 홀수이면 분자가 감소, 분모가 증가 (오른쪽 위 방향)
// i가 짝수이면 분자가 증가, 분모가 감소 (왼쪽 아래 방향)

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int X, s=0, i=1;
    cin >> X;
    
    while (X > s+i) {
        s += i;
        ++i;
    }
    
    int k = X - s;
    
    if (i & 1) cout << i-k+1 << '/' << k;
    else cout << k << '/' << i-k+1;

    return 0;
}
