// https://www.acmicpc.net/problem/10093
// 10093번 숫자
// 단순 구현 문제
// 두 수의 차와 사이의 값을 오름차순으로 정렬해 출력하여 해결 가능

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long long A, B;
    
    scanf("%lld %lld", &A, &B);

    if (A > B) swap(A, B);
    
    printf("%lld\n", max((long long)0, B-A-1));
    while (++A < B) printf("%lld ", A);

    return 0;
}
