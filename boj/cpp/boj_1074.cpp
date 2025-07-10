// https://www.acmicpc.net/problem/1074
// 1074번 Z
// 분할 정복 문제
// 전체 배열을 4분할 하고 앞의 사분면에 대한 위치를 누적하여 해결 가능
// 전체 배열을 4분할 왼쪽 위, 오른쪽, 왼쪽 아래, 오른쪽 아래
// (r, c)가 어느 사분면에 속하는지를 판단
// 해당 사분면 이전까지의 칸수를 더해가며 재귀적으로 위치 추적

#include <iostream>
#include <cmath>

using namespace std;

int find(int r, int c, int n) {
    if (n <= 2) return r*2+c;
    
    int y = (int)(r >= n/2);
    int x = (int)(c >= n/2);
    
    if (y) r -= n/2;
    if (x) c -= n/2;
    
    int now = pow(n/2, 2);
    int nowPos = now*y*2 + now*x;
    
    return nowPos + find(r, c, n/2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, r, c;
    cin >> N >> r >> c;
    
    int res = find(r, c, pow(2, N));
    cout << res;

    return 0;
}
